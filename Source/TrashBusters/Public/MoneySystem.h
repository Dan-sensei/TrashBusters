// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "GameHUD.h"
#include "MoneySystem.generated.h"

/**
 * 
 */
UCLASS()
class TRASHBUSTERS_API AMoneySystem : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Money")
	float Balance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Money")
	UGameHUD* HUD;

private:
	AMoneySystem();

public:
	UFUNCTION(BlueprintCallable, Category = "Money")
	void IncreaseBalance(float increase);
};
