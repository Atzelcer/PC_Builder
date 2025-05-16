// Fill out your copyright notice in the Description page of Project Settings.


#include "MinasTipo2.h"
#include "UObject/ConstructorHelpers.h"

AMinasTipo2::AMinasTipo2()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	if (MeshAsset.Succeeded())
	{
		MinaMesh->SetStaticMesh(MeshAsset.Object);
	}
}