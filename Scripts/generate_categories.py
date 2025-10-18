#!/usr/bin/env python3
"""
Generate data/categories.txt from ManuTool header files.

Scans ManuTool/Headers (and ManuTool) for L"Item Name" occurrences and groups
them by header-derived category (filename after items_ or Items_).
Writes output as TSV: Category<TAB>ItemName (one per line) to data/categories.txt.

Usage:
  python scripts/generate_categories.py --headers ManuTool/Headers --out data/categories.txt
"""

import os
import re
import argparse
from collections import OrderedDict

def find_headers(dirpath):
    files = []
    for root,_,fnames in os.walk(dirpath):
        for fn in fnames:
            if fn.lower().endswith('.h') and ('items' in fn.lower()):
                files.append(os.path.join(root, fn))
    return sorted(files)

def category_from_filename(fname):
    # examples: items_Helmet.h, Items_Hat.h, Items_Costume.h
    base = os.path.basename(fname)
    stem = os.path.splitext(base)[0]
    # split on underscore
    parts = stem.split('_', 1)
    if len(parts) == 2 and parts[0].lower().startswith('items'):
        return parts[1]
    # if begins with items
    if stem.lower().startswith('items'):
        return stem[5:]
    # fallback: use stem
    return stem

def extract_items_from_file(path):
    try:
        data = open(path, 'r', encoding='utf-8', errors='ignore').read()
    except Exception:
        return []
    # find L"..." or {L"..."
    items = []
    for m in re.finditer(r'L"([^"]+)"', data):
        name = m.group(1).strip()
        if not name:
            continue
        # skip obvious non-item entries
        if 'base' in name.lower() or 'compound' in name.lower():
            continue
        items.append(name)
    # dedupe preserving order
    seen = set()
    uniq = []
    for it in items:
        if it not in seen:
            seen.add(it)
            uniq.append(it)
    return uniq

def main():
    p = argparse.ArgumentParser()
    p.add_argument('--headers', default='../ManuTool')
    p.add_argument('--out', default='../Data/categories.txt')
    args = p.parse_args()

    headers = find_headers(args.headers)
    categories = OrderedDict()
    for h in headers:
        cat = category_from_filename(h)
        items = extract_items_from_file(h)
        if not items:
            continue
        if cat not in categories:
            categories[cat] = []
        categories[cat].extend(items)

    # fallback: also scan top-level ManuTool items_*.h if present
    topdir = os.path.dirname(args.headers) or 'ManuTool'
    for fn in os.listdir(topdir) if os.path.isdir(topdir) else []:
        if fn.lower().startswith('items') and fn.lower().endswith('.h'):
            path = os.path.join(topdir, fn)
            cat = category_from_filename(fn)
            items = extract_items_from_file(path)
            if items:
                categories.setdefault(cat, []).extend(items)

    os.makedirs(os.path.dirname(args.out), exist_ok=True)
    with open(args.out, 'w', encoding='utf-8') as fo:
        for cat, items in categories.items():
            for it in items:
                fo.write(f"{cat}\t{it}\n")
    print(f"Wrote {args.out} ({sum(len(v) for v in categories.values())} entries)")

if __name__ == '__main__':
    main()