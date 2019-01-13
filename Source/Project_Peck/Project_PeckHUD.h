// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Project_PeckHUD.generated.h"

UCLASS()
class AProject_PeckHUD : public AHUD
{
	GENERATED_BODY()

public:
	AProject_PeckHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

