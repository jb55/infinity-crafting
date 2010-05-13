#include "Crafting.h"
#include "CComponent.h"

using namespace CRAFTING_NAMESPACE_NAME;

int main(void)
{
    float stats[kNumStats] = {0,1,2,3,4,5,6,7,8,9,10,11};
    CComponent component(stats, kNumStats);

    return 0;
}
