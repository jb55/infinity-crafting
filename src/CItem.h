
#ifndef _CRAFT_ITEM_H_
#define _CRAFT_ITEM_H_

#include "Crafting.h"
#include "CModifierGroup.h"
#include <string>

CRAFTING_NAMESPACE

class CItem 
{
public:
    CItem();
    CItem(float *stats, int count);
    ~CItem();
    
    float getBaseStat(ModifierType stat) const;
    void  setBaseStat(ModifierType stat, float value);
    float getStat(ModifierType stat); 

    std::string getName() { return "UnknownItem"; }

    CModifierGroup &getModifierGroup();

private:
    CModifierGroup m_modGroup;
    float m_baseStats[kNumMods];
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_ITEM_H_ */
