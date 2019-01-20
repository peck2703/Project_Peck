// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h
#include "SpawnComponent.generated.h"


class PROJECT_PECK_API USpawnComponent : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<AActor*> ActorsToSpawn;
		
	
};
