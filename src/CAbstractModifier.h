#ifndef _CRAFT_ABSTRACT_MODIFIER_H_
#define _CRAFT_ABSTRACT_MODIFIER_H_
#pragma once

CRAFTING_NAMESPACE

/**
 * @interface CAbstractModifier
 * @brief An interface to modifiers, all modifiers derive from the interface
 *
 * The CAbstractModifier class defines an interface for which all modifiers must
 * conform. To be considered a modifier you must derive from this class.
 *
 * CAbstractModifiers are perticularily useful when dealing with groups
 * of modifiers. @see CModifierGroup
 */
class CAbstractModifier
{
public:
    /**
     * Gets the modifier value of a given type
     *
     * @param type Modifier type to retrieve
     * @return The modifier value
     */
    virtual float getRawModifier(ModifierType type) = 0;

    /**
     * Gets all modifiers associated with this modifier
     *
     * @param mods An array of floating point modifier values to return.
     *             Classes deriving this interface must store modifier values
     *             into the passed in array.
     *
     * @return modMask A bitmask that records which modifiers were
     *                 returned in the mods parameter. Bits correspond with the
     *                 ModifierTypeFlags or simply (1 << ModifierType).
     *                 When a modifier value is stored in the mods parameter,
     *                 the modMask must be OR'd with the ModifierTypeFlag to
     *                 conform to this interface.
     */
    virtual void getRawModifiers(float mods[kNumMods], unsigned *modMask) = 0;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_ABSTRACT_MODIFIER_H_ */
