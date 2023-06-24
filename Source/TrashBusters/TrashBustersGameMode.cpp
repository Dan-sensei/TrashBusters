// Copyright Epic Games, Inc. All Rights Reserved.

#include "TrashBustersGameMode.h"
#include "TrashBustersCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATrashBustersGameMode::ATrashBustersGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
