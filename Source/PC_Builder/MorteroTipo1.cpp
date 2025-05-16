// Fill out your copyright notice in the Description page of Project Settings.


#include "MorteroTipo1.h"
#include "UObject/ConstructorHelpers.h"

AMorteroTipo1::AMorteroTipo1()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
	if (MeshAsset.Succeeded())
	{
		MorteroMesh->SetStaticMesh(MeshAsset.Object);
	}
}