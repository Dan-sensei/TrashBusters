// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TrashGeneratorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRASHBUSTERS_API UTrashGeneratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTrashGeneratorComponent();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrashSpawning")
	int TrashToGenerate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrashSpawning")
	TSubclassOf<AActor> BP_Trash;
};
