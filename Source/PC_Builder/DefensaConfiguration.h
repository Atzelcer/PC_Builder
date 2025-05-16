// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanoDefensa.h"
#include "DefenderInterface.h"
#include "DefensaConfiguration.generated.h"

UCLASS()
class PC_BUILDER_API ADefensaConfiguration : public AActor, public IPlanoDefensa
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADefensaConfiguration();

	IDefenderInterface* Builder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	int32 CantidadTorretas;
	int32 CantidadMinas;
	int32 CantidadMorteros;

	virtual void Tick(float DeltaTime) override;
	virtual void EstablecerTorretas() override;
	virtual void EstablecerMinas() override;
	virtual void EstablecerMorteros() override;
	virtual void EstablecerBuild(AActor* ConstructorConcrete) override;
};
