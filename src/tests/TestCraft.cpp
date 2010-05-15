#include "Crafting.h"
#include "CModifier.h"
#include "CComponentModifier.h"
#include "CItem.h"
#include "CModifierGroup.h"
#include "CPointsModifier.h"
#include <iostream>

using namespace CRAFTING_NAMESPACE_NAME;


// A helper function to simplify the main part.
std::ostream& operator<<(std::ostream& os, CItem& c)
{
    os << "CItem " << c.getName() << std::endl;

    os << "  base: ";
    for (int i = 0; i < kNumMods; i++) {
        os << c.getBaseStat(static_cast<ModifierType>(i)) << ", ";
    }

    os << std::endl << "  modified: ";
    for (int i = 0; i < kNumMods; i++) {
        os << c.getStat(static_cast<ModifierType>(i)) << ", ";
    }

    return os;
}


int main(void)
{
    float stats[kNumMods] = 
        {46,1520,0.2,330,20,30,735,17,0.2,4000,330,0.8,840,260};
    CItem item(stats, kNumMods);

    // component mod
    CModifier cArmor(kArmorThickness, 0.15);
    CModifier cHitpoints(kHitpoints, 0.04);
    CModifier cReflectiveness(kHullReflectiveness, 0.12);
    CModifier cMass(kMass, 0.08);

    CComponentModifier component;
    component
        .addModifier(cArmor)
        .addModifier(cHitpoints)
        .addModifier(cReflectiveness)
        .addModifier(cMass);

    CPointsModifier points(30, 30, 65);

    item.getModifierGroup()
        .addModifier(&component)
        .addModifier(&points);

    std::cout << item << std::endl;
    return 0;
}
