#include "CPointsModifier.h"
#include <math.h>
#include <iostream>

CRAFTING_NAMESPACE

CPointsModifier::CPointsModifier(
    int speedPoints, int efficiencyPoints, int qualityPoints,
    PointFunction speedFn,
    PointFunction efficiencyFn,
    PointFunction qualityFn)
{
    speedFn = speedFn ? speedFn : CPointsModifier::defaultSpeedCalc;
    efficiencyFn = efficiencyFn ? efficiencyFn : CPointsModifier::defaultEffCalc;
    qualityFn = qualityFn ? qualityFn : CPointsModifier::defaultQualityCalc;

    m_speed = speedFn(speedPoints);
    m_efficiency = efficiencyFn(efficiencyPoints);
    m_quality = qualityFn(qualityPoints);

    std::cout << m_speed << " " << m_efficiency << " " << m_quality << std::endl;

    for (int i = 0; i < kNumStats; i++) {
        const ModifierType type = static_cast<ModifierType>(i);
        m_modifiers[i].setModifierType(type);
        m_modifiers[i].setModifierValue(m_quality * kStatSigns[type]);
        addModifier(&m_modifiers[i]);
    }
}

CPointsModifier::~CPointsModifier() {
}

float CPointsModifier::getSpeed() const {
    return m_speed;
}

float CPointsModifier::getEfficiency() const {
    return m_efficiency;
}

float CPointsModifier::getQuality() const {
    return m_quality;
}

float CPointsModifier::defaultQualityCalc(int points) {
    return baseCalc(0.03155, 0.6, 0, points);
}

float CPointsModifier::defaultEffCalc(int points) {
    return baseCalc(-0.05, 0.5, 1, points);
}

float CPointsModifier::defaultSpeedCalc(int points) {
    return baseCalc(-0.08, 0.5, 1, points);
}

float CPointsModifier::baseCalc(float coEff, float power, float add, int points) {
    return (coEff * pow(static_cast<float>(points), power)) + add;
}

CRAFTING_NAMESPACE_END
