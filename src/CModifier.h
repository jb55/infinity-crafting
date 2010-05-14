#ifndef _CRAFT_MODIFIER_H_
#define _CRAFT_MODIFIER_H_
#pragma once

#include "Crafting.h"
#include "CComponent.h"
#include "CAbstractModifier.h"

CRAFTING_NAMESPACE

class CModifier : public CAbstractModifier
{
public:
    CModifier(StatType modifierTypes, float value);
    virtual ~CModifier();

    virtual void getMods(float *mods, unsigned *modMask);
    virtual void mutateComponent(CComponent *component);
    virtual CComponent transformComponent(const CComponent &component);

    StatType getModifierType() const;
    float getModifierValue() const;

private:
    StatType m_modType;
    float m_value;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_H_ */
