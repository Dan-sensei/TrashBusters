// Fill out your copyright notice in the Description page of Project Settings.


#include "TrashGeneratorComponent.h"

// Sets default values for this component's properties
UTrashGeneratorComponent::UTrashGeneratorComponent()
:TrashToGenerate(5)
{
	
}

// (X=-7120.000000,Y=4880.000000,Z=300.000000)
// Called when the game starts
void UTrashGeneratorComponent::BeginPlay()
{
	Super::BeginPlay();
	AActor* parent = GetOwner();
	
	FVector Origin;
	FVector Extend;

	parent->GetActorBounds(false, Origin, Extend, false);
	
	FVector LowerCorner = Origin - Extend;
	FVector UpperCorner = Origin + Extend;

	FVector RandomPoint;
	for (int i = 0; i < TrashToGenerate; ++i) {
		RandomPoint.X = FMath::RandRange(LowerCorner.X, UpperCorner.X);
		RandomPoint.Y = FMath::RandRange(LowerCorner.Y, UpperCorner.Y);
		RandomPoint.Z = (UpperCorner.Z - LowerCorner.Z) / 2 + LowerCorner.Z;

		AActor* Spawned = GetWorld()->SpawnActor<AActor>(BP_Trash, RandomPoint, FRotator());
	}

}


