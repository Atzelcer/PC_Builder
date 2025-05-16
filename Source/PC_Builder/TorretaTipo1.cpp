// Fill out your copyright notice in the Description page of Project Settings.


#include "TorretaTipo1.h"
#include "UObject/ConstructorHelpers.h"

ATorretaTipo1::ATorretaTipo1()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	if (MeshAsset.Succeeded())
	{
		TorretaMesh->SetStaticMesh(MeshAsset.Object);
	}
}