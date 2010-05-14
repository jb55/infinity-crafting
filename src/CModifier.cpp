
#include "CModifier.h"

CRAFTING_NAMESPACE

CModifier::CModifier(StatTypeFlags type, float value)
    : m_modType(type), m_value(value)
{
}

CModifier::~CModifier() {
}

void CModifier::mutateComponent(CComponent *component) const 
{
    unsigned modType = this->getModifierTypes();
    const float modValue = this->getModifierValue();

    for (int j = 0, k = 0; modType && j < kNumStats; j++, modType >>= 1) {
        if (modType & 1) {
            const StatType type = static_cast<StatType>(j);
            const float currentValue = component->getBaseStat(type);
            const float newValue = currentValue + (currentValue * modValue);
            component->setBaseStat(type, newValue);
        }
    }
}

CComponent CModifier::transformComponent(const CComponent &component) const 
{
    CComponent trans(component);
    mutateComponent(&trans);
    return trans;
}

StatTypeFlags CModifier::getModifierTypes() const {
    return m_modType;
}

float CModifier::getModifierValue() const {
    return m_value;
}

CRAFTING_NAMESPACE_END

