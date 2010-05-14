#ifndef _CRAFT_MODIFIER_GROUP_H_
#define _CRAFT_MODIFIER_GROUP_H_
#pragma once

#include "CModifier.h"
#include "CComponent.h"
#include <vector>

CRAFTING_NAMESPACE

class CModifierGroup : public CAbstractModifier
{
public:
    CModifierGroup();
    virtual ~CModifierGroup();

    typedef std::vector<CAbstractModifier*> ModList;

    CModifierGroup& addModifier(CAbstractModifier *modifier);
    CModifierGroup& removeModifier(const CModifier &modifier);

    const ModList& getModifiers() const;

    virtual void getMods(float *mods, unsigned *modMask);
    virtual void mutateComponent(CComponent *component);
    virtual CComponent transformComponent(const CComponent &component);

private:
    ModList m_modifiers;
};


CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_GROUP_H_ */
