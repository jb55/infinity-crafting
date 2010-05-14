#ifndef _CRAFT_COMPONENT_H_
#define _CRAFT_COMPONENT_H_

#include "Crafting.h"

CRAFTING_NAMESPACE

class CComponent 
{
public:
    CComponent();
    CComponent(float *stats, int count);
    ~CComponent();
    
    float getBaseStat(ModifierType stat) const;
    void  setBaseStat(ModifierType stat, float value);

private:

    float m_baseStats[kNumStats];
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_COMPONENT_H_ */
