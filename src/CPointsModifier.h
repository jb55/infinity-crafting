#ifndef _CRAFT_POINTS_MODIFIER_H_
#define _CRAFT_POINTS_MODIFIER_H_
#pragma once

#include "CModifierGroup.h"
#include "CModifier.h"

CRAFTING_NAMESPACE

class CPointsModifier : public CModifierGroup
{
public:
    typedef float (*PointFunction)(int);

    CPointsModifier(int speedPoints, int efficiencyPoints, int qualityPoints,
                    PointFunction speedFn = 0,
                    PointFunction efficiencyFn = 0,
                    PointFunction qualityFn = 0);

    virtual ~CPointsModifier();

    float getSpeed() const;
    float getEfficiency() const;
    float getQuality() const;

private:
    CModifier m_modifiers[kNumStats];
    float m_speed, m_efficiency, m_quality;

    static float defaultSpeedCalc(int points);
    static float defaultEffCalc(int points);
    static float defaultQualityCalc(int points);

    static float baseCalc(float coEff, float pow, float add, int points);
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_POINTS_MODIFIER_H_ */
