// Fill out your copyright notice in the Description page of Project Settings.


#include "MoneySystem.h"

AMoneySystem::AMoneySystem ():Balance(0.f){
}

void AMoneySystem::IncreaseBalance(float increase){
    Balance += increase;
    HUD->setBalance(Balance);
}