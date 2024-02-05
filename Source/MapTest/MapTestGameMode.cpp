// Copyright Epic Games, Inc. All Rights Reserved.

#include "MapTestGameMode.h"
#include "MapTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMapTestGameMode::AMapTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
