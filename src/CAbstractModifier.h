#ifndef _CRAFT_ABSTRACT_MODIFIER_H_
#define _CRAFT_ABSTRACT_MODIFIER_H_
#pragma once

CRAFTING_NAMESPACE

class CAbstractModifier
{
public:
    virtual float getRawModifier(ModifierType type) = 0;
    virtual void getRawModifiers(float *mods, unsigned *modMask) = 0;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_ABSTRACT_MODIFIER_H_ */
