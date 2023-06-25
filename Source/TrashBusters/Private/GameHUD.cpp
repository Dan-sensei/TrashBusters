// Fill out your copyright notice in the Description page of Project Settings.

#include "GameHUD.h"

void UGameHUD::SetTrashBags(int target, float bagPercentage) {
    for(int i = 0; i < target; ++i)
        DisplayTrashBag(target, 1);

    DisplayTrashBag(target, bagPercentage);
}