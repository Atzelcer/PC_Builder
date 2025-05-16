// Fill out your copyright notice in the Description page of Project Settings.


#include "DefensaFuturistaBuilder.h"
#include "TorretaTipo2.h"
#include "MinasTipo2.h"
#include "MorteroTipo2.h"
#include "Engine/Engine.h"
#include "DefensaConfiguration.h"

// Sets default values
ADefensaFuturistaBuilder::ADefensaFuturistaBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Defensa = nullptr;
}

// Called when the game starts or when spawned
void ADefensaFuturistaBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADefensaFuturistaBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADefensaFuturistaBuilder::ConstruirTorretas(int32 CantidadTorretas)
{
	for (int32 i = 0; i < CantidadTorretas; ++i)
	{
		FVector Pos = FVector(1000.f, i * 150.f, 230.f);
		GetWorld()->SpawnActor<ATorretaTipo2>(ATorretaTipo2::StaticClass(), Pos, FRotator::ZeroRotator);
	}
	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Orange, TEXT("Torretas futuristas construidas."));
}

void ADefensaFuturistaBuilder::ConstruirMinas(int32 CantidadMinas)
{
	for (int32 i = 0; i < CantidadMinas; ++i)
	{
		FVector Pos = FVector(1300.f, i * 150.f, 230.f);
		GetWorld()->SpawnActor<AMinasTipo2>(AMinasTipo2::StaticClass(), Pos, FRotator::ZeroRotator);
	}
	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Yellow, TEXT("Minas futuristas colocadas."));
}

void ADefensaFuturistaBuilder::ConstruirMorteros(int32 CantidadMorteros)
{
	for (int32 i = 0; i < CantidadMorteros; ++i)
	{
		FVector Pos = FVector(1600.f, i * 150.f, 230.f);
		GetWorld()->SpawnActor<AMorteroTipo2>(AMorteroTipo2::StaticClass(), Pos, FRotator::ZeroRotator);
	}
	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Cyan, TEXT("Morteros futuristas desplegados."));
}

ADefensaConfiguration* ADefensaFuturistaBuilder::ObtenerDefensa()
{
	return Defensa;
}

