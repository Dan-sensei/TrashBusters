// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UGameHUD;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRASHBUSTERS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 maxTrashBags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int collectedTrash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int maxTrashPerbag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float balance;

private:
	UGameHUD* HUD;

public:	
	void IncreaseBalance(float increase);
	void IncreaseTrashCount();
	bool CanPickUp();
	inline void IncreaseMaxTrashBags() { ++maxTrashBags; }
	inline void SetHUD(UGameHUD* hud) { HUD = hud; }
};
