// Fill out your copyright notice in the Description page of Project Settings.


#include "TorretaTipo2.h"
#include "UObject/ConstructorHelpers.h"

ATorretaTipo2::ATorretaTipo2()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MeshAsset.Succeeded())
	{
		TorretaMesh->SetStaticMesh(MeshAsset.Object);
	}
}