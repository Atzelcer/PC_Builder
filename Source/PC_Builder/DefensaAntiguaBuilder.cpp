// Fill out your copyright notice in the Description page of Project Settings.


#include "DefensaAntiguaBuilder.h"
#include "TorretaTipo1.h"
#include "MinasTipo1.h"
#include "MorteroTipo1.h"
#include "Engine/Engine.h"
#include "DefensaConfiguration.h"

// Sets default values
ADefensaAntiguaBuilder::ADefensaAntiguaBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Defensa = nullptr;
}

// Called when the game starts or when spawned
void ADefensaAntiguaBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADefensaAntiguaBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADefensaAntiguaBuilder::ConstruirTorretas(int32 CantidadTorretas)
{
	for (int32 i = 0; i < CantidadTorretas; ++i)
	{
		FVector Pos = FVector(0.f, i * 150.f, 230.f);
		GetWorld()->SpawnActor<ATorretaTipo1>(ATorretaTipo1::StaticClass(), Pos, FRotator::ZeroRotator);
	}
	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Orange, TEXT("Torretas antiguas construidas."));
}

void ADefensaAntiguaBuilder::ConstruirMinas(int32 CantidadMinas)
{
	for (int32 i = 0; i < CantidadMinas; ++i)
	{
		FVector Pos = FVector(300.f, i * 150.f, 230.f);
		GetWorld()->SpawnActor<AMinasTipo1>(AMinasTipo1::StaticClass(), Pos, FRotator::ZeroRotator);
	}
	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Yellow, TEXT("Minas antiguas colocadas."));
}

void ADefensaAntiguaBuilder::ConstruirMorteros(int32 CantidadMorteros)
{
	for (int32 i = 0; i < CantidadMorteros; ++i)
	{
		FVector Pos = FVector(600.f, i * 150.f, 230.f);
		GetWorld()->SpawnActor<AMorteroTipo1>(AMorteroTipo1::StaticClass(), Pos, FRotator::ZeroRotator);
	}
	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Cyan, TEXT("Morteros antiguos desplegados."));
}

ADefensaConfiguration* ADefensaAntiguaBuilder::ObtenerDefensa()
{
	return Defensa;
}

