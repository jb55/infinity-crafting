#ifndef _CRAFT_MODIFIER_H_
#define _CRAFT_MODIFIER_H_
#pragma once

CRAFTING_NAMESPACE

class CModifier 
{
public:
    CModifier(StatType modifierType, float value);
    ~CModifier();

    int getModifierType() const;
    float getModifierValue() const;

private:
    int m_modType;
    float m_value;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_MODIFIER_H_ */
