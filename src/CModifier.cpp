
#include "CModifier.h"

CRAFTING_NAMESPACE

int CModifier::getModifierType() const {
    return m_modType;
}

float CModifier::getModifierValue() const {
    return m_value;
}

CRAFTING_NAMESPACE_END

