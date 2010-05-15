#include "CItem.h"
#include <iostream>

CRAFTING_NAMESPACE

CItem::CItem() 
{
    for (int i = 0; i < kNumMods; i++) {
        m_baseStats[i] = 0;
    }
}

CItem::CItem(float *stats, int num)
{
    for (int i = 0; i < num; i++) {
        m_baseStats[i] = stats[i];
    }
}

CItem::~CItem() {
}

void CItem::setBaseStat(ModifierType stat, float value) {
    m_baseStats[stat] = value;
}

float CItem::getBaseStat(ModifierType stat) const {
    return m_baseStats[stat];
}

float CItem::getStat(ModifierType stat) {
    CModifierGroup &modGroup = this->getModifierGroup();
    if (modGroup.getModifiers().size() == 0)
        return 0.0;
    const float rawMod = modGroup.getRawModifier(stat);
    const float currentValue = this->getBaseStat(stat);
    float newValue = currentValue + (currentValue * rawMod);
    return newValue;
}

CModifierGroup &CItem::getModifierGroup() {
    return m_modGroup;
}

CRAFTING_NAMESPACE_END
