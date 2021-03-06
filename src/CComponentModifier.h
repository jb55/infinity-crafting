#ifndef _CRAFT_COMPONENT_MODIFIER_H_
#define _CRAFT_COMPONENT_MODIFIER_H_

#include "Crafting.h"
#include "CModifierGroup.h"

CRAFTING_NAMESPACE

/**
 * @class CPointsModifier
 * @brief An example modifier group, associated with a component
 *        in the crafting system.
 */
class CComponentModifier : public CModifierGroup
{
public:
    CComponentModifier();
    CComponentModifier(float *modifiers, int count);
    virtual ~CComponentModifier();
    
private:
    CModifier m_modifiers[kNumMods];
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_COMPONENT_MODIFIER_H_ */
