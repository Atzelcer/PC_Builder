// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DefenderInterface.h"
#include "Director.generated.h"

UCLASS()
class PC_BUILDER_API UDirector : public UObject
{
	GENERATED_BODY()

private:
	IDefenderInterface* Builder;
	class ADefensaConfiguration* Defensa;

public:
	void SelectBuilder(IDefenderInterface* NewBuilder);
	void SetDefensaConfiguration(ADefensaConfiguration* NuevaDefensa);
	void Make();
	void ResetBuild();
	ADefensaConfiguration* GetConfiguracionBuilder() const;
};
