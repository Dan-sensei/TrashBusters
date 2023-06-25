// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHUD.generated.h"

UCLASS()
class TRASHBUSTERS_API UGameHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category = "Money")
	void SetBalance(float balance);
	void SetTrashBags(int completedBags, float bagPercentage);
	UFUNCTION(BlueprintImplementableEvent,Category = "Money")
	void DisplayTrashBag(int target, float bagPercentage);
};
