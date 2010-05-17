
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

void CModifier::getRawModifiers(float mods[kNumMods], unsigned *modMask)
{
    const ModifierType modType = this->getType();
    mods[modType] = this->getValue();
    *modMask |= 1 << modType;
}

float CModifier::getRawModifier(ModifierType type) 
{
    if (type != this->getType())
        return 0.0;
    return this->getValue();
}

ModifierType CModifier::getType() const {
    return m_modType;
}

void CModifier::setType(ModifierType type) {
    m_modType = type;
}

void CModifier::setValue(float value) {
    m_value = value;
}

float CModifier::getValue() const {
    return m_value;
}

CRAFTING_NAMESPACE_END

