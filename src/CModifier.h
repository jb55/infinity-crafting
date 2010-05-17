#ifndef _CRAFT_MODIFIER_H_
#define _CRAFT_MODIFIER_H_
#pragma once

#include "Crafting.h"
#include "CAbstractModifier.h"

CRAFTING_NAMESPACE

/**
 * @class CModifier
 * @brief A simple modifier which modifies a single stat
 */
class CModifier : public CAbstractModifier
{
public:

    CModifier(ModifierType modifierTypes, float value);
    CModifier();
    virtual ~CModifier();

    virtual float getRawModifier(ModifierType type);
    virtual void getRawModifiers(float mods[kNumMods], unsigned *modMask);

    /**
     * Gets the type that this modifier is modifying
     *
     * @return The modifier type
     */
    ModifierType getType() const;

    /**
     * Gets the modifier value, this value is usually a floating point
     * value between 0 and 1 representing a percentage.
     *
     * @return The modifier value
     */
    float getValue() const;

    /**
     * Sets the value of the modifier
     *
     * @param value The new modifier value to replace the old one
     */
    void setValue(float value);

    /**
     * Sets the modifier type
     *
     * @param type The modifier type
     */
    void setType(ModifierType type);

private:
    ModifierType m_modType;
    float m_value;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_H_ */
