#ifndef _CRAFT_MODIFIER_H_
#define _CRAFT_MODIFIER_H_
#pragma once

#include "Crafting.h"
#include "CComponent.h"

CRAFTING_NAMESPACE

class CModifier 
{
public:
    CModifier(StatTypeFlags modifierTypes, float value);
    ~CModifier();

    void mutateComponent(CComponent *component) const;
    CComponent transformComponent(const CComponent &component) const;

    StatTypeFlags getModifierTypes() const;
    float getModifierValue() const;

private:
    StatTypeFlags m_modType;
    float m_value;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_H_ */
