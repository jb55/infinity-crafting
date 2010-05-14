#ifndef _CRAFT_ABSTRACT_MODIFIER_H_
#define _CRAFT_ABSTRACT_MODIFIER_H_
#pragma once

CRAFTING_NAMESPACE

class CAbstractModifier
{
public:
    virtual void getMods(float *mods, unsigned *modMask) = 0;
    virtual void mutateComponent(CComponent *component) = 0;
    virtual CComponent transformComponent(const CComponent &component) = 0;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_ABSTRACT_MODIFIER_H_ */
