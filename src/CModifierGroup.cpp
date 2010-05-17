#include "CModifierGroup.h"
#include <iostream>

CRAFTING_NAMESPACE

CModifierGroup::~CModifierGroup() {
    StoredModList::iterator mod = m_storedModifiers.begin();
    for (; mod != m_storedModifiers.end(); ++mod) {
        delete *mod;
    }
}

CModifierGroup::CModifierGroup() {
}

float CModifierGroup::getRawModifier(ModifierType type) 
{
    ModList::iterator mod = m_modifiers.begin();
    float sumMod = 0.0;
    for (; mod != m_modifiers.end(); ++mod) {
        sumMod += (*mod)->getRawModifier(type);
    }
    return sumMod;
}

const CModifierGroup::ModList &CModifierGroup::getModifiers() const {
    return m_modifiers;
}

void CModifierGroup::getRawModifiers(float mods[kNumMods], unsigned *modMask) 
{
    // TODO: Performance - memoize this when the modifiers haven't changed

    ModList::iterator mod = m_modifiers.begin();
    float subMods[kNumMods] = {0.0};
    unsigned subModMask = 0;
    for (; mod != m_modifiers.end(); ++mod) {
        (*mod)->getRawModifiers(subMods, &subModMask);
        for (int i = 0; subModMask && i < kNumMods; i++, subModMask >>= 1) {
            if (subModMask & 1) {
                mods[i] += subMods[i];
                *modMask |= 1 << i;
                subMods[i] = 0.0;
            }
        }
    }

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

CModifierGroup& CModifierGroup::addModifier(const CModifier &modifier) {
    m_storedModifiers.push_back(new CModifier(modifier));
    CAbstractModifier *abstractModifier = m_storedModifiers.back();
    return addModifier(abstractModifier);
}

CModifierGroup& CModifierGroup::addModifier(CAbstractModifier *modifier) {
    m_modifiers.push_back(modifier);
    return *this;
}

CRAFTING_NAMESPACE_END
