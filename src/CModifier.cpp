
#include "CModifier.h"

CRAFTING_NAMESPACE

CModifier::CModifier() {
}

CModifier::CModifier(ModifierType type, float value)
    : m_modType(type), m_value(value)
{
}

CModifier::~CModifier() {
}

void CModifier::getMods(float *mods, unsigned *modMask)
{
    const ModifierType modType = this->getModifierType();
    mods[modType] = this->getModifierValue();
    *modMask |= 1 << modType;
}

void CModifier::mutateComponent(CComponent *component)
{
    const ModifierType modType = this->getModifierType();
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

ModifierType CModifier::getModifierType() const {
    return m_modType;
}

void CModifier::setModifierType(ModifierType type) {
    m_modType = type;
}

void CModifier::setModifierValue(float value) {
    m_value = value;
}

float CModifier::getModifierValue() const {
    return m_value;
}

CRAFTING_NAMESPACE_END

