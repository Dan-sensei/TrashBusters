// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PickableTrashComponent.generated.h"

UENUM(BlueprintType)
enum class TrashType : uint8
{
  TrashType_PlasticBottle,
  TrashType_GlassBottle,
  TrashType_Paper,
  TrashType_SodaCan,
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRASHBUSTERS_API UPickableTrashComponent : public UActorComponent
{
  GENERATED_BODY()

public:	
  UPickableTrashComponent();

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TrashType bTrashType;
};
