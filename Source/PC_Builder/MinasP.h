// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MinasP.generated.h"

UCLASS()
class PC_BUILDER_API AMinasP : public AActor
{
	GENERATED_BODY()
	
public:
	AMinasP();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UStaticMeshComponent* MinaMesh;
};
