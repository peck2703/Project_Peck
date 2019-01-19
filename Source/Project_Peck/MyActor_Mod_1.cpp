// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor_Mod_1.h"
#include "GameFramework/Actor.h"


// Sets default values
AMyActor_Mod_1::AMyActor_Mod_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Add the mesh
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	//Set the Root to the created mesh
	RootComponent = mesh;
}

// Called when the game starts or when spawned
void AMyActor_Mod_1::BeginPlay()
{
	//This method causes an issue when building, so for now I'll comment it out
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor_Mod_1::Tick(float DeltaTime)
{
	//This method causes an issue when building, so for now I'll comment it out
	Super::Tick(DeltaTime);

}

void AMyActor_Mod_1::PostActorCreated()
{
	//Super:: throws an error, so I placed AActor in its place for the meantime, I'll test it out and see if it'll work
	Super::PostActorCreated();

	//Call the create square method
	CreateSquare();
}

void AMyActor_Mod_1::PostLoad()
{
	Super::PostLoad();
	//Call the create square method
	CreateSquare();
}

void AMyActor_Mod_1::CreateSquare()
{
	//Set up a TArray to hold vertices
	TArray<FVector> Vertices;

	//Set up an array of triangles
	TArray<int32> Triangles;

	//Set up array for Normals
	TArray <FVector> Normals;

	//Set up array for colors
	TArray < FLinearColor > Colors;

	//Add values to Vertices
	Vertices.Add(FVector(0.f, 0.f, 0.f));
	Vertices.Add(FVector(0.f, 100.f, 0.f));
	Vertices.Add(FVector(0.f, 0.f, 100.f));
	Vertices.Add(FVector(0.f, 100.f, 100.f));

	//Adding triangle values to array
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(3);
	Triangles.Add(2);
	Triangles.Add(1);

	//for loop that adds normals and colors to all vertices
	for (int32 i = 0; i < Vertices.Num(); i++) {
		Normals.Add(FVector(0.f, 0.f, 1.f));
		Colors.Add(FLinearColor::Red);
	} // Optional arrays.

	//set up array for UVs
	TArray <FVector2D> UV0;

	//set up array for tangents
	TArray <FProcMeshTangent> Tangents;

	//adds a mesh section to the mesh created in constructor
	mesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0, Colors, Tangents, true);
}

