
#include "CModifier.h"

CRAFTING_NAMESPACE

CModifier::CModifier(StatType type, float value)
    : m_modType(type), m_value(value)
{
}

CModifier::~CModifier() {
}

void CModifier::getMods(float *mods, unsigned *modMask)
{
    const StatType modType = this->getModifierType();
    mods[modType] = this->getModifierValue();
    *modMask |= 1 << modType;
}

void CModifier::mutateComponent(CComponent *component)
{
    const StatType modType = this->getModifierType();
    const float modValue = this->getModifierValue();
    const float currentValue = component->getBaseStat(modType);
    const float newValue = currentValue + (currentValue * modValue);
    component->setBaseStat(modType, newValue);
}

CComponent CModifier::transformComponent(const CComponent &component)
{
    CComponent trans(component);
    mutateComponent(&trans);
    return trans;
}

StatType CModifier::getModifierType() const {
    return m_modType;
}

float CModifier::getModifierValue() const {
    return m_value;
}

CRAFTING_NAMESPACE_END

