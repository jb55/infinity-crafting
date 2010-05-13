#include "CComponent.h"
#include "CModifierGroup.h"

CRAFTING_NAMESPACE

void CModifierGroup::mutateComponent(CComponent *component) 
{
    m_modifiers::const_iterator i = m_modifiers.begin();
    for (; i != m_modifiers.end(); ++i) {
        const CModifier &mod = *i;
        const int modType = mod.getModifierType();
        const float modValue = mod.getModifierValue();
        const float currentValue = component->getBaseStat(modType);
        component->setBaseStat(modType, currentValue * modValue);
    }
}

CComponent CModifierGroup::transformComponent(const CComponent &component) 
{
    CComponent trans(component);
    mutateComponent(&trans);
    return trans;
}

void CModifierGroup::removeModifier(const CModifier &modifier) {
    m_modifiers::iterator i = m_modifiers.begin();
    for (; i != m_modifiers.end(); ++i) {
        const CModifier *lhs = &*i;
        const CModifier *rhs = &modifier;
        if (lhs->getModifierType() == rhs->getModifierType() &&
            lhs->getModifierValue() == rhs->getModifierValue()) 
        {
            modifier.erase(i);
            return;
        }
    }
}

void CModifierGroup::addModifier(const CModifier &modifier) {
    m_modifiers.push_back(modifier);
}

CRAFTING_NAMESPACE_END
