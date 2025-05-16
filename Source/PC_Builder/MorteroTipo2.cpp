// Fill out your copyright notice in the Description page of Project Settings.


#include "MorteroTipo2.h"
#include "UObject/ConstructorHelpers.h"

AMorteroTipo2::AMorteroTipo2()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe_90.Shape_Pipe_90'"));
	if (MeshAsset.Succeeded())
	{
		MorteroMesh->SetStaticMesh(MeshAsset.Object);
	}
}
