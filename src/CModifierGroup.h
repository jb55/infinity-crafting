#ifndef _CRAFT_MODIFIER_GROUP_H_
#define _CRAFT_MODIFIER_GROUP_H_
#pragma once

#include "CModifier.h"
#include <vector>

CRAFTING_NAMESPACE

class CModifierGroup : public CAbstractModifier
{
public:
    CModifierGroup();
    virtual ~CModifierGroup();

    typedef std::vector<CAbstractModifier*> ModList;

    CModifierGroup& addModifier(const CModifier &modifier);
    CModifierGroup& addModifier(CAbstractModifier *modifier);
    CModifierGroup& removeModifier(const CModifier &modifier);

    const ModList& getModifiers() const;

    virtual float getRawModifier(ModifierType type);
    virtual void getRawModifiers(float *mods, unsigned *modMask);

private:

    typedef std::vector<CModifier*> StoredModList;

    StoredModList m_storedModifiers;
    ModList m_modifiers;
};


CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_GROUP_H_ */
