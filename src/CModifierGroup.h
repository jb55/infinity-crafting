#ifndef _CRAFT_MODIFIER_GROUP_H_
#define _CRAFT_MODIFIER_GROUP_H_
#pragma once

#include "CModifier.h"
#include "CComponent.h"
#include <vector>

CRAFTING_NAMESPACE

class CModifierGroup 
{
public:
    CModifierGroup();
    ~CModifierGroup();

    typedef std::vector<CModifier> ModList;

    CModifierGroup& addModifier(const CModifier &modifier);
    CModifierGroup& removeModifier(const CModifier &modifier);
    CModifierGroup& mergeGroup(const CModifierGroup &group);

    const ModList& getModifiers() const;

    void mutateComponent(CComponent *component);
    CComponent transformComponent(const CComponent &component);

private:
    ModList m_modifiers;
};


CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_GROUP_H_ */
