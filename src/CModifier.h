#ifndef _CRAFT_MODIFIER_H_
#define _CRAFT_MODIFIER_H_
#pragma once

#include "Crafting.h"

CRAFTING_NAMESPACE

class CModifier 
{
public:
    CModifier(StatType modifierType, float value);
    ~CModifier();

    StatType getModifierType() const;
    float getModifierValue() const;

private:
    StatType m_modType;
    float m_value;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_H_ */
