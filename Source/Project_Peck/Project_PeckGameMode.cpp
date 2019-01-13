// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Project_PeckGameMode.h"
#include "Project_PeckHUD.h"
#include "Project_PeckCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_PeckGameMode::AProject_PeckGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProject_PeckHUD::StaticClass();
}
