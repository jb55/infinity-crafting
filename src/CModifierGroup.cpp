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
    float modSum[kNumStats] = {0.0};
    unsigned modMask = 0;

    this->getMods(modSum, &modMask);

    for (unsigned i = 0; modMask && i < kNumStats; i++, modMask >>= 1) {
        const ModifierType type = static_cast<ModifierType>(i);
        CModifier sumMod(type, modSum[i]);
        sumMod.mutateComponent(component);
    }
}

void CModifierGroup::getMods(float *mods, unsigned *modMask) 
{
    ModList::iterator mod = m_modifiers.begin();
    float subMods[kNumStats] = {0.0};
    unsigned subModMask = 0;
    for (; mod != m_modifiers.end(); ++mod) {
        (*mod)->getMods(subMods, &subModMask);
        for (int i = 0; subModMask && i < kNumStats; i++, subModMask >>= 1) {
            if (subModMask & 1) {
                mods[i] += subMods[i];
                *modMask |= 1 << i;
                subMods[i] = 0.0;
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

// implement equality compare for CComponentTransformer
CModifierGroup& CModifierGroup::removeModifier(const CModifier &modifier)
{
#if 0
    ModList::iterator i = m_modifiers.begin();
    for (; i != m_modifiers.end(); ++i) {
        const CModifier *lhs = *i;
        const CModifier *rhs = &modifier;
        if (lhs->getModifierType() == rhs->getModifierType() &&
            lhs->getModifierValue() == rhs->getModifierValue())
        {
            m_modifiers.erase(i);
            return *this;
        }
    }
#endif
    return *this;
}

CModifierGroup& CModifierGroup::addModifier(CAbstractModifier *modifier) {
    m_modifiers.push_back(modifier);
    return *this;
}

CRAFTING_NAMESPACE_END
