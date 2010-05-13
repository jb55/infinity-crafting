#ifndef _CRAFT_MODIFIER_H_
#define _CRAFT_MODIFIER_H_
#pragma once

#include "Crafting.h"

CRAFTING_NAMESPACE

class CModifier 
{
public:
    CModifier(StatTypeFlags modifierTypes, float value);
    ~CModifier();

    StatTypeFlags getModifierType() const;
    float getModifierValue() const;

private:
    StatTypeFlags m_modType;
    float m_value;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_H_ */
