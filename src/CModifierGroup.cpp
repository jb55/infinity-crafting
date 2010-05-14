#include "CComponent.h"
#include "CModifierGroup.h"
#include <iostream>

CRAFTING_NAMESPACE

CModifierGroup::~CModifierGroup() {
}

CModifierGroup::CModifierGroup() {
}

void CModifierGroup::mutateComponent(CComponent *component)
{
    ModList::const_iterator mod = m_modifiers.begin();

    /**
     * For increased performance this paragraph can be replaced
     * by introducing state. You can add the modSums when adding
     * and removing new modifiers. This is a lazy approach and
     * will be less buggy.
     */
    float modSum[kNumStats] = {0.0};
    unsigned modMask = 0;
    for (; mod != m_modifiers.end(); ++mod) {
        unsigned types = mod->getModifierTypes();
        for (int i = 0; types && i < kNumStats; i++, types >>= 1) {
            if (types & 1) {
                modSum[i] += mod->getModifierValue();
                modMask |= 1 << i;
            }
        }
    }

    for (int i = 0; modMask && i < kNumStats; i++, modMask >>= 1) {
        const StatTypeFlags typeFlag = static_cast<StatTypeFlags>(1 << i);
        std::cout << modSum[i] << std::endl;
        CModifier sumMod(typeFlag, modSum[i]);
        sumMod.mutateComponent(component);
    }
}

CModifierGroup& CModifierGroup::mergeGroup(const CModifierGroup &group)
{
    return *this;
}

CComponent CModifierGroup::transformComponent(const CComponent &component)
{
    CComponent trans(component);
    mutateComponent(&trans);
    return trans;
}

CModifierGroup& CModifierGroup::removeModifier(const CModifier &modifier) {
    ModList::iterator i = m_modifiers.begin();
    for (; i != m_modifiers.end(); ++i) {
        const CModifier *lhs = &*i;
        const CModifier *rhs = &modifier;
        if (lhs->getModifierTypes() == rhs->getModifierTypes() &&
            lhs->getModifierValue() == rhs->getModifierValue())
        {
            m_modifiers.erase(i);
            return *this;
        }
    }
}

CModifierGroup& CModifierGroup::addModifier(const CModifier &modifier) {
    m_modifiers.push_back(modifier);
    return *this;
}

CRAFTING_NAMESPACE_END
