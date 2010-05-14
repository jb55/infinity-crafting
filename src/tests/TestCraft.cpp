#include "Crafting.h"
#include "CComponent.h"
#include "CModifier.h"
#include "CModifierGroup.h"
#include <iostream>

using namespace CRAFTING_NAMESPACE_NAME;


// A helper function to simplify the main part.
std::ostream& operator<<(std::ostream& os, const CComponent& c)
{
    os << "CComponent ";
    for (int i = 0; i < kNumStats; i++) {
        os << c.getBaseStat(static_cast<StatType>(i)) << ", ";
    }
    return os;
}


int main(void)
{
    float stats[kNumStats] = {46,1520,0.2,330,20,30,735,17,0.2,4000,330,0.8};
    CComponent component(stats, kNumStats);

    // component mod
    CModifier cArmor(kArmorThickness, 0.15);
    CModifier cHitpoints(kHitpoints, 0.04);
    CModifier cReflectiveness(kHullReflectiveness, 0.12);
    CModifier cMass(kMass, 0.08);
    //CModifier cOverallQuality(kAllStats, 0.37);

    CModifierGroup group;
      group
        .addModifier(&cArmor)
        .addModifier(&cHitpoints)
        .addModifier(&cReflectiveness)
        .addModifier(&cMass);

    CModifierGroup applyTwice;
      applyTwice
        .addModifier(&group)
        .addModifier(&group);

    std::cout << component << std::endl;
    CComponent newComponent = group.transformComponent(component);
    std::cout << newComponent << std::endl;
    newComponent = applyTwice.transformComponent(component);
    std::cout << newComponent << std::endl;

    return 0;
}
