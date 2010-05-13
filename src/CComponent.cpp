#include "CComponent.h"

CRAFTING_NAMESPACE

CComponent::CComponent() 
{
    for (int i = 0; i < kNumStats; i++) {
        m_baseStats[i] = 0;
    }
}

CComponent::CComponent(float *stats, int num)
{
    for (int i = 0; i < num; i++) {
        m_baseStats[i] = stats[i];
    }
}

CComponent::~CComponent() {
}

void CComponent::setBaseStat(StatType stat, float value) {
    m_baseStats[stat] = value;
}

float CComponent::getBaseStat(StatType stat) const {
    return m_baseStats[stat];
}

CRAFTING_NAMESPACE_END
