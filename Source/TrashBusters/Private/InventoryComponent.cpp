// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "GameHUD.h"

UInventoryComponent::UInventoryComponent() :
maxTrashBags(1),
collectedTrash(0), 
maxTrashPerbag(5),
balance(0)
{}

void UInventoryComponent::IncreaseBalance(float increase)
{
	balance += increase;
    HUD->SetBalance(balance);
}

void UInventoryComponent::IncreaseTrashCount()
{
	if(maxTrashPerbag == 0) 
	{
		return;
	}

	++collectedTrash;
	int fullBags = collectedTrash/maxTrashPerbag;
	float lastBagPercentage = (collectedTrash % maxTrashPerbag) / static_cast<float>(maxTrashPerbag);
    HUD->SetTrashBags(fullBags, lastBagPercentage);
}

bool UInventoryComponent::CanPickUp()
{
	return collectedTrash / (maxTrashPerbag * maxTrashBags) < 1;
}
