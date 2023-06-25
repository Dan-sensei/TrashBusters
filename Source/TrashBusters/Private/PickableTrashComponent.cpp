#include "PickableTrashComponent.h"

namespace PickableTrashHelpers
{
    float GetScoreFromType(TrashType type)
    {
        switch (type)
        {
        case TrashType::TrashType_SodaCan:
        case TrashType::TrashType_PlasticBottle: return 10.f;
        case TrashType::TrashType_GlassBottle: return 20.f;
        case TrashType::TrashType_Paper: return 5.f;
        default: break;
        }
        return 0.f;
    }
}

// Sets default values for this component's properties
UPickableTrashComponent::UPickableTrashComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

float UPickableTrashComponent::GetScore() const
{
    return PickableTrashHelpers::GetScoreFromType(bTrashType);
}
