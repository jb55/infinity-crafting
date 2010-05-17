#ifndef _CRAFT_MODIFIER_GROUP_H_
#define _CRAFT_MODIFIER_GROUP_H_
#pragma once

#include "CModifier.h"
#include <vector>

CRAFTING_NAMESPACE

/**
 * @class CModifierGroup
 * @brief A container that combines modifiers into a single modifier
 *
 * A modifier group is a simple container that holds a list of
 * modifiers. Note that the modifier group itself is a modifier,
 * so you can add other modifier groups to a modifier group.
 *
 * The resulting modifiers is simply a sum of all contained modifiers.
 * If you would like a product of all contained modifiers, you can
 * derive from this class and overload getRawModifiers and getRawModifier.
 */
class CModifierGroup : public CAbstractModifier
{
public:
    CModifierGroup();
    virtual ~CModifierGroup();

    typedef std::vector<CAbstractModifier*> ModList;

    /**
     * Adds a CModifier to the modifier group
     * This overload permanently stores a stack-allocated CModifier
     * by copying it onto the heap. This is mainly for convenience.
     *
     * @param modifier A stack-allocated modifier
     * @return A reference to this modifier group (used to chain operations)
     */
    CModifierGroup& addModifier(const CModifier &modifier);

    /**
     * Adds a modifier to the modifier group
     *
     * @param modifier A pointer to a modifier, the pointer is expected
     *                 to be valid for the lifetime of the CModifierGroup
     *                 object.
     * @return A reference to this modifier group (used to chain operations)
     */
    CModifierGroup& addModifier(CAbstractModifier *modifier);

    /**
     * Removes a modifer (NOT IMPLEMENTED)
     */
    CModifierGroup& removeModifier(const CModifier &modifier);

    /**
     * Gets the list of modifiers contained in this group
     *
     * @return A vector of CAbstractModifier pointers
     */
    const ModList& getModifiers() const;

    virtual float getRawModifier(ModifierType type);
    virtual void getRawModifiers(float mods[kNumMods], unsigned *modMask);

private:

    typedef std::vector<CModifier*> StoredModList;

    StoredModList m_storedModifiers;
    ModList m_modifiers;
};


CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_GROUP_H_ */
