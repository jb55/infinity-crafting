#include "CComponent.h"
#include "CModifierGroup.h"

CRAFTING_NAMESPACE

void CModifierGroup::mutateComponent(CComponent *component) 
{
    ModList::const_iterator i = m_modifiers.begin();
    for (; i != m_modifiers.end(); ++i) {
        const CModifier &mod = *i;
        const StatTypeFlags modType = mod.getModifierType();
        const float modValue = mod.getModifierValue();
        for (int j = 0, k = 0; j < kNumStats; j++) {
            k = 1 << j;
            if (k & modType) {
                const StatType type = static_cast<StatType>(j);
                const float currentValue = component->getBaseStat(type);
                component->setBaseStat(type, currentValue * modValue);
            }
        }
    }
}

CComponent CModifierGroup::transformComponent(const CComponent &component) 
{
    CComponent trans(component);
    mutateComponent(&trans);
    return trans;
}

void CModifierGroup::removeModifier(const CModifier &modifier) {
    ModList::iterator i = m_modifiers.begin();
    for (; i != m_modifiers.end(); ++i) {
        const CModifier *lhs = &*i;
        const CModifier *rhs = &modifier;
        if (lhs->getModifierType() == rhs->getModifierType() &&
            lhs->getModifierValue() == rhs->getModifierValue()) 
        {
            m_modifiers.erase(i);
            return;
        }
    }
}

void CModifierGroup::addModifier(const CModifier &modifier) {
    m_modifiers.push_back(modifier);
}

CRAFTING_NAMESPACE_END
