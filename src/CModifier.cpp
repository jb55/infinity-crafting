
#include "CModifier.h"

CRAFTING_NAMESPACE

CModifier::CModifier(StatType type, float value)
    : m_modType(type), m_value(value)
{
}

CModifier::~CModifier() {
}

StatType CModifier::getModifierType() const {
    return m_modType;
}

float CModifier::getModifierValue() const {
    return m_value;
}

CRAFTING_NAMESPACE_END

