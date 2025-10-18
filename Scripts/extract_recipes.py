#!/usr/bin/env python3
"""
Simple extractor for AddRecipe(...) calls in ManuTool/Recipes/*.cpp

It finds lines like:
  AddRecipe(L"Name", { Mat(L"X", 1), Tool(L"T",1) });
or
  AddRecipe(L"Name", 4, { Mat(...), ... });

It writes a plain text file with an easy-to-parse format (data/recipes.txt):

===RECIPE===
Name: <name>
Yield: <yield or 1>
Input: M|Cowhide|5
Input: T|Anvil|1
Input: S|SubRecipe|2

This format is intentionally simple for the minimal viewer app.
"""
import argparse
import re
import os
import sys

ADD_RECIPE_RE = re.compile(r'AddRecipe\s*\(\s*L"([^"]+)"\s*(?:,\s*([0-9]+))?\s*,\s*\{', re.MULTILINE)
INPUT_RE = re.compile(r'\b(Mat|Tool|Sub)\s*\(\s*L"([^"]+)"\s*,\s*([0-9]+)\s*\)', re.MULTILINE)

def extract_from_file(path):
    text = open(path, encoding='utf-8', errors='ignore').read()
    recipes = []
    for m in ADD_RECIPE_RE.finditer(text):
        name = m.group(1)
        yield_count = m.group(2)
        # find the brace block starting at m.end()-1
        start = m.end() - 1
        # naive bracket matching to find corresponding closing '}'
        depth = 0
        end = start
        for i in range(start, len(text)):
            if text[i] == '{':
                depth += 1
            elif text[i] == '}':
                depth -= 1
                if depth == 0:
                    end = i
                    break
        block = text[start:end+1]
        inputs = []
        for im in INPUT_RE.finditer(block):
            typ = im.group(1)  # Mat / Tool / Sub
            nm = im.group(2)
            qty = int(im.group(3))
            if typ == 'Mat':
                t = 'M'
            elif typ == 'Tool':
                t = 'T'
            else:
                t = 'S'
            inputs.append((t, nm, qty))
        recipes.append({'name': name, 'yield': int(yield_count) if yield_count else 1, 'inputs': inputs})
    return recipes

def scan_dir(src_dir):
    all_recipes = []
    for root, dirs, files in os.walk(src_dir):
        for f in files:
            if f.endswith('.cpp') or f.endswith('.c') or f.endswith('.cc') or f.endswith('.hpp'):
                path = os.path.join(root, f)
                try:
                    r = extract_from_file(path)
                    if r:
                        all_recipes.extend(r)
                except Exception as e:
                    print(f"Warning: failed to parse {path}: {e}", file=sys.stderr)
    return all_recipes

def write_out(recipes, out_path):
    os.makedirs(os.path.dirname(out_path), exist_ok=True)
    with open(out_path, 'w', encoding='utf-8') as fo:
        for rec in recipes:
            fo.write("===RECIPE===\n")
            fo.write(f"Name: {rec['name']}\n")
            fo.write(f"Yield: {rec['yield']}\n")
            for inp in rec['inputs']:
                fo.write(f"Input: {inp[0]}|{inp[1]}|{inp[2]}\n")
            fo.write("\n")
    print(f"Wrote {len(recipes)} recipes to {out_path}")

def main():
    p = argparse.ArgumentParser(description="Extract recipes from ManuTool/Recipes")
    p.add_argument('--src', default='../Recipes', help='Source folder to scan')
    p.add_argument('--out', default='data/recipes.txt', help='Output recipes file (plain text)')
    args = p.parse_args()
    if not os.path.isdir(args.src):
        print(f"Error: source directory not found: {args.src}", file=sys.stderr)
        sys.exit(1)
    recipes = scan_dir(args.src)
    write_out(recipes, args.out)

if __name__ == '__main__':
    main()