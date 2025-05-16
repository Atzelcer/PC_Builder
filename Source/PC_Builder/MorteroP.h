// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MorteroP.generated.h"

UCLASS()
class PC_BUILDER_API AMorteroP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMorteroP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UStaticMeshComponent* MorteroMesh;
};