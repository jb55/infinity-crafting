#ifndef _CRAFT_MODIFIER_GROUP_H_
#define _CRAFT_MODIFIER_GROUP_H_
#pragma once

CRAFTING_NAMESPACE

class CModifierGroup 
{
public:
    CModifierGroup();
    ~CModifierGroup();

    void addModifier(const CModifier &modifier);
    void removeModifier(const CModifier &modifier);
    void mutateComponent(CComponent *component);
    CComponent transformComponent(const CComponent &component);

private:
    std::vector<CModifier> m_modifiers;
};


CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_GROUP_H_ */
