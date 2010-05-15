#include "CComponentModifier.h"

CRAFTING_NAMESPACE

CComponentModifier::CComponentModifier() {
}

CComponentModifier::CComponentModifier(float *modifiers, int count)
{
    for (int i = 0; i < count; i++) {
        const float value = modifiers[i];
        if (value == 0.0)
            continue;
        const ModifierType type = static_cast<ModifierType>(i);
        addModifier(CModifier(type, value));
    }
}

CComponentModifier::~CComponentModifier() {
}

CRAFTING_NAMESPACE_END
