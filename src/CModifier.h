#ifndef _CRAFT_MODIFIER_H_
#define _CRAFT_MODIFIER_H_
#pragma once

#include "Crafting.h"
#include "CAbstractModifier.h"

CRAFTING_NAMESPACE

class CModifier : public CAbstractModifier
{
public:
    CModifier(ModifierType modifierTypes, float value);
    CModifier();
    virtual ~CModifier();

    virtual float getRawModifier(ModifierType type);
    virtual void getRawModifiers(float mods[kNumMods], unsigned *modMask);

    ModifierType getType() const;
    float getValue() const;

    void setValue(float value);
    void setType(ModifierType type);

private:
    ModifierType m_modType;
    float m_value;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_H_ */
