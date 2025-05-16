// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DefenderInterface.h"
#include "DefensaAntiguaBuilder.generated.h"

UCLASS()
class PC_BUILDER_API ADefensaAntiguaBuilder : public AActor, public IDefenderInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADefensaAntiguaBuilder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	class ADefensaConfiguration* Defensa;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void ConstruirTorretas(int32 CantidadTorretas) override;
	virtual void ConstruirMinas(int32 CantidadMinas) override;
	virtual void ConstruirMorteros(int32 CantidadMorteros) override;
	virtual ADefensaConfiguration* ObtenerDefensa() override;

};
