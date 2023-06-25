// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharaceter.h"

// Sets default values
ATestCharaceter::ATestCharaceter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestCharaceter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestCharaceter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestCharaceter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

