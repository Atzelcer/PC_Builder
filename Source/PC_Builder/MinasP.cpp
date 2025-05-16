// Fill out your copyright notice in the Description page of Project Settings.


#include "MinasP.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AMinasP::AMinasP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MinaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MinaMesh"));
	RootComponent = MinaMesh;

}

// Called when the game starts or when spawned
void AMinasP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMinasP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

