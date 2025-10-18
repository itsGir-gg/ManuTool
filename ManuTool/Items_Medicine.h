#pragma once
#include "resource.h"

struct IconEntry { const wchar_t* name; int resId; };

static const IconEntry kItems_Medicine[] = {
    {L"Weak HP Potion",                         IDI_WEAK_HP_POTION},
    {L"Mediocre HP Potion",                     IDI_MEDIOCRE_HP_POTION},
    {L"Average HP Potion",                      IDI_AVERAGE_HP_POTION},
    {L"Strong HP Potion",                       IDI_STRONG_HP_POTION},
    {L"Super HP Potion",                        IDI_SUPER_HP_POTION},
    {L"Weak MP Potion",                         IDI_WEAK_MP_POTION},
    {L"Average MP Potion",                      IDI_AVERAGE_MP_POTION},
    {L"Strong MP Potion",                       IDI_STRONG_MP_POTION},
    {L"Super MP Potion",                        IDI_SUPER_MP_POTION},
    {L"Digestive Pill",                         IDI_DIGESTIVE_PILL},
    {L"Stomach Pill",                           IDI_STOMACH_PILL},
    {L"Anti-Cancer Pill",                       IDI_ANTI_CANCER_PILL},
    {L"Glaze",                                  IDI_GLAZE},
    {L"Stinky Soup(60 seconds)",                IDI_STINKY_SOUP},
    {L"Gold Soup",                              IDI_GOLD_SOUP},
    {L"Polisher",                               IDI_POLISHER},
    {L"Bleach",                                 IDI_BLEACH},
    {L"Leather Protector",                      IDI_LEATHER_PROTECTOR},
    {L"Lubricant",                              IDI_LUBRICANT},
    {L"Hypertension Pill",                      IDI_HYPERTENSION_PILL},
    {L"Cold Pill",                              IDI_COLD_PILL},
    {L"Headache Pill",                          IDI_HEADACHE_PILL},
    {L"Strange HP Potion for Summons",          IDI_STRANGE_HP_POTION_FOR_SUMMONS},
    {L"Mysterious HP Potion for Summons",       IDI_MYSTERIOUS_HP_POTION_FOR_SUMMONS},
    {L"MP Potion for Summoned Monster",         IDI_MP_POTION_FOR_SUMMONED_MONSTER},
    {L"Antidotes",                              IDI_ANTIDOTES},
};
static constexpr size_t kItems_Medicine_Count = _countof(kItems_Medicine);