// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PC_BuilderGameMode.generated.h"

UCLASS(minimalapi)
class APC_BuilderGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APC_BuilderGameMode();

public:
	virtual void BeginPlay() override;
};



