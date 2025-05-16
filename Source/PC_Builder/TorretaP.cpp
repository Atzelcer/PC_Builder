// Fill out your copyright notice in the Description page of Project Settings.


#include "TorretaP.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ATorretaP::ATorretaP()
{
	PrimaryActorTick.bCanEverTick = true;

	TorretaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TorretaMesh"));
	RootComponent = TorretaMesh;
}

void ATorretaP::BeginPlay()
{
	Super::BeginPlay();
}

void ATorretaP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
