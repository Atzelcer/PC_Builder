// Fill out your copyright notice in the Description page of Project Settings.


#include "MinasTipo1.h"
#include "UObject/ConstructorHelpers.h"

AMinasTipo1::AMinasTipo1()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (MeshAsset.Succeeded())
	{
		MinaMesh->SetStaticMesh(MeshAsset.Object);
	}
}