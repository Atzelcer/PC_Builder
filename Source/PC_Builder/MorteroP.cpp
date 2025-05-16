// Fill out your copyright notice in the Description page of Project Settings.


#include "MorteroP.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AMorteroP::AMorteroP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MorteroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MorteroMesh"));
	RootComponent = MorteroMesh;
}

// Called when the game starts or when spawned
void AMorteroP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMorteroP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

