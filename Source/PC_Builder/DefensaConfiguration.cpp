// Fill out your copyright notice in the Description page of Project Settings.


#include "DefensaConfiguration.h"
//#include "S_DefensaAntiguoBuilder.h"
#include "Engine/Engine.h"

// Sets default values
ADefensaConfiguration::ADefensaConfiguration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADefensaConfiguration::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADefensaConfiguration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADefensaConfiguration::EstablecerBuild(AActor* ConstructorConcrete)
{
	if (!ConstructorConcrete)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Objeto constructor recibido es NULL..."));
		return;
	}

	Builder = Cast<IDefenderInterface>(ConstructorConcrete);

	if (Builder)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Builder establecido correctamente"));
	}
	else if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Error al establecer el builder"));
	}
}


void ADefensaConfiguration::EstablecerTorretas()
{
	if (Builder)
	{
		Builder->ConstruirTorretas(CantidadTorretas);
	}
	else if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Builder no asignado: no se pueden construir torretas."));
	}
}

void ADefensaConfiguration::EstablecerMinas()
{
	if (Builder)
		Builder->ConstruirMinas(CantidadMinas);
	else if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Builder no asignado: no se pueden construir minas."));
}

void ADefensaConfiguration::EstablecerMorteros()
{
	if (Builder)
		Builder->ConstruirMorteros(CantidadMorteros);
	else if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Builder no asignado: no se pueden construir morteros."));
}

