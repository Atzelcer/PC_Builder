// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DefenderInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDefenderInterface : public UInterface
{
	GENERATED_BODY()
};


class PC_BUILDER_API IDefenderInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

public:

    virtual void ConstruirTorretas(int32 CantidadTorretas) = 0;
    virtual void ConstruirMinas(int32 CantidadMinas) = 0;
    virtual void ConstruirMorteros(int32 CantidadMorteros) = 0;
    virtual class ADefensaConfiguration* ObtenerDefensa() = 0;
};
