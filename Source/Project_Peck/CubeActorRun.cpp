// Fill out your copyright notice in the Description page of Project Settings.

#include "CubeActorRun.h"
#include "GameFramework/Actor.h"
#include "RuntimeMeshComponent.h"

// Sets default values
ACubeActorRun::ACubeActorRun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Add the mesh
	mesh = CreateDefaultSubobject<URuntimeMeshComponent>(TEXT("GeneratedMesh"));
	//Set the Root to the created mesh
	RootComponent = mesh;
}

// Called when the game starts or when spawned
void ACubeActorRun::BeginPlay()
{
	AActor::BeginPlay();
	
}

// Called every frame
void ACubeActorRun::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);

}

void ACubeActorRun::PostActorCreated()
{
	//Super:: throws an error, so I placed AActor in its place for the meantime, I'll test it out and see if it'll work
	Super::PostActorCreated();

	//Call the create square method
	CreateSquare();
}

void ACubeActorRun::PostLoad()
{
	Super::PostLoad();
	//Call the create square method
	CreateSquare();
}

void ACubeActorRun::CreateSquare()
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
	TArray <FRuntimeMeshTangent> Tangents;
}

void ACubeActorRun::GenerateBoxMesh()
{
	//Create array of Vertices
	TArray<FVector> Vertices;

	//Create array of normals
	TArray<FVector> Normals;

	//Create array of tangents
	TArray<FRuntimeMeshTangent> Tangents;

	//Create array of coordinate vertices to place texture
	TArray<FVector2D> TextureCoordinates;

	//Create array of triangles
	TArray<int32> Triangles;

	//Create array of colors
	TArray<FColor> Colors;

	//Create the box mesh using the arrays above
	CreateBoxMesh(FVector(50, 50, 50), Vertices, Triangles, Normals, TextureCoordinates, Tangents, Colors);

	//this creates the actual mesh section with collision
	mesh->CreateMeshSection(0, Vertices, Triangles, Normals, TextureCoordinates, Colors, Tangents, true);
}

void ACubeActorRun::CreateBoxMesh(FVector BoxRadius, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UVs, TArray<FRuntimeMeshTangent>& Tangents, TArray<FColor>& Colors)
{
	//Set the length of the Vector array (changed value to 8)
	FVector BoxVerts[8];

	//Sets up the vertices as a normal box (sides of length 1)
	BoxVerts[0] = FVector(-BoxRadius.X, BoxRadius.Y, BoxRadius.Z);			// (-1, 1, 1)
	BoxVerts[1] = FVector(BoxRadius.X, BoxRadius.Y, BoxRadius.Z);			// (1, 1, 1)
	BoxVerts[2] = FVector(BoxRadius.X, -BoxRadius.Y, BoxRadius.Z);			// (1, -1, 1)
	BoxVerts[3] = FVector(-BoxRadius.X, -BoxRadius.Y, BoxRadius.Z);			// (-1, -1, 1)
	BoxVerts[4] = FVector(-BoxRadius.X, BoxRadius.Y, -BoxRadius.Z);			// (-1, 1, -1)
	BoxVerts[5] = FVector(BoxRadius.X, BoxRadius.Y, -BoxRadius.Z);			// (1, 1, -1)
	BoxVerts[6] = FVector(BoxRadius.X, -BoxRadius.Y, -BoxRadius.Z);			// (-1, 1, 1)
	BoxVerts[7] = FVector(-BoxRadius.X, -BoxRadius.Y, -BoxRadius.Z);		// (-1, -1, -1)

																			//Reset the triangles
	Triangles.Reset();
	//6 sides for each box x 4 verts ea. face
	const int32 NumVerts = 24;
	//Reset the colors
	Colors.Reset();
	//Add colors based on length of NumVerts
	Colors.AddUninitialized(NumVerts);

	//For loop that every third vertices is a different color
	for (int i = 0; i < NumVerts / 3; i++) {
		Colors[i * 3] = FColor(255, 0, 0);
		Colors[i * 3 + 1] = FColor(0, 255, 0);
		Colors[i * 3 + 2] = FColor(0, 0, 255);
	}

	//Reset the vertices
	Vertices.Reset();
	//Add vertices based on NumVerts
	Vertices.AddUninitialized(NumVerts);
	//Reset normals
	Normals.Reset();
	//Add normals based on NumVerts
	Normals.AddUninitialized(NumVerts);
	//Reset Tangents
	Tangents.Reset();
	//Add tangents based on NumVerts
	Tangents.AddUninitialized(NumVerts);

	//Initialize vertices to match up to BoxVerts
	Vertices[0] = BoxVerts[0];
	Vertices[1] = BoxVerts[1];
	Vertices[2] = BoxVerts[2];
	Vertices[3] = BoxVerts[3];

	//Adding Triangles
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(3);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(3);

	//Multiple set up of normals to (0,0,1)
	Normals[0] = Normals[1] = Normals[2] = Normals[3] = FVector(0, 0, 1);

	//Multiple set up of tangents to (0, -1, 0)
	Tangents[0] = Tangents[1] = Tangents[2] = Tangents[3] = FRuntimeMeshTangent(0.f, -1.f, 0.f);

	//Intialize more vertices to match up to BoxVerts
	Vertices[4] = BoxVerts[4];
	Vertices[5] = BoxVerts[0];
	Vertices[6] = BoxVerts[3];
	Vertices[7] = BoxVerts[7];

	//Adding triangles
	Triangles.Add(4);
	Triangles.Add(5);
	Triangles.Add(7);
	Triangles.Add(5);
	Triangles.Add(6);
	Triangles.Add(7);

	//Multiple set up of normals to (-1, 0, 0)
	Normals[4] = Normals[5] = Normals[6] = Normals[7] = FVector(-1, 0, 0);

	//Multiple set up of tangents to (0, -1, 0)
	Tangents[4] = Tangents[5] = Tangents[6] = Tangents[7] = FRuntimeMeshTangent(0.f, -1.f, 0.f);

	//Initialize more vertices to match up to BoxVerts
	Vertices[8] = BoxVerts[5];
	Vertices[9] = BoxVerts[1];
	Vertices[10] = BoxVerts[0];
	Vertices[11] = BoxVerts[4];

	//Adding triangles
	Triangles.Add(8);
	Triangles.Add(9);
	Triangles.Add(11);
	Triangles.Add(9);
	Triangles.Add(10);
	Triangles.Add(11);

	//Multiple set up of normals to (0, 1, 0)
	Normals[8] = Normals[9] = Normals[10] = Normals[11] = FVector(0, 1, 0);

	//Multiple set up of tangents to (-1, 0, 0)
	Tangents[8] = Tangents[9] = Tangents[10] = Tangents[11] = FRuntimeMeshTangent(-1.f, 0.f, 0.f);

	//Initialize more vertices to match up to BoxVerts
	Vertices[12] = BoxVerts[6];
	Vertices[13] = BoxVerts[2];
	Vertices[14] = BoxVerts[1];
	Vertices[15] = BoxVerts[5];

	//Adding triangles
	Triangles.Add(12);
	Triangles.Add(13);
	Triangles.Add(15);
	Triangles.Add(13);
	Triangles.Add(14);
	Triangles.Add(15);

	//Multiple set up of normals to (1, 0, 0)
	Normals[12] = Normals[13] = Normals[14] = Normals[15] = FVector(1, 0, 0);

	//Multiple set up of tangents to (0, 1, 0)
	Tangents[12] = Tangents[13] = Tangents[14] = Tangents[15] = FRuntimeMeshTangent(0.f, 1.f, 0.f);

	//Initialize more vertices to match up to BoxVerts
	Vertices[16] = BoxVerts[7];
	Vertices[17] = BoxVerts[3];
	Vertices[18] = BoxVerts[2];
	Vertices[19] = BoxVerts[6];

	//Adding triangles
	Triangles.Add(16);
	Triangles.Add(17);
	Triangles.Add(19);
	Triangles.Add(17);
	Triangles.Add(18);
	Triangles.Add(19);

	//Multiple set up of normals to (0, -1, 0)
	Normals[16] = Normals[17] = Normals[18] = Normals[19] = FVector(0, -1, 0);

	//Multiple set up of tangents to (1, 0, 0)
	Tangents[16] = Tangents[17] = Tangents[18] = Tangents[19] = FRuntimeMeshTangent(1.f, 0.f, 0.f);

	//Initialize more vertices to match up to BoxVerts
	Vertices[20] = BoxVerts[7];
	Vertices[21] = BoxVerts[6];
	Vertices[22] = BoxVerts[5];
	Vertices[23] = BoxVerts[4];

	//Adding triangles
	Triangles.Add(20);
	Triangles.Add(21);
	Triangles.Add(23);
	Triangles.Add(21);
	Triangles.Add(22);
	Triangles.Add(23);

	//Multiple set up of normals to (0, 0, -1)
	Normals[20] = Normals[21] = Normals[22] = Normals[23] = FVector(0, 0, -1);

	//Multiple set up of tangents to (0, 1, 0)
	Tangents[20] = Tangents[21] = Tangents[22] = Tangents[23] = FRuntimeMeshTangent(0.f, 1.f, 0.f);

	//Reset the UV values
	UVs.Reset();
	//Add UVs based on NumVerts
	UVs.AddUninitialized(NumVerts);
	//Multiple set up (every fourth value) as a x,y value (normalized)

	//Side One
	UVs[0] = UVs[4] = UVs[8] = UVs[12] = UVs[16] = UVs[20] = FVector2D(0.f, 0.f);
	//Side Two
	UVs[1] = UVs[5] = UVs[9] = UVs[13] = UVs[17] = UVs[21] = FVector2D(0.f, 1.f);
	//Side Three
	UVs[2] = UVs[6] = UVs[10] = UVs[14] = UVs[18] = UVs[22] = FVector2D(1.f, 1.f);
	//Side Four
	UVs[3] = UVs[7] = UVs[11] = UVs[15] = UVs[19] = UVs[23] = FVector2D(1.f, 0.f);
}