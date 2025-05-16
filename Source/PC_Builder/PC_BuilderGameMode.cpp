// Copyright Epic Games, Inc. All Rights Reserved.

#include "PC_BuilderGameMode.h"
#include "PC_BuilderPlayerController.h"
#include "PC_BuilderCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Director.h"
#include "DefenderInterface.h"
#include "DefensaAntiguaBuilder.h"
#include "DefensaFuturistaBuilder.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/Engine.h"
#include "DefensaConfiguration.h"

APC_BuilderGameMode::APC_BuilderGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = APC_BuilderPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void APC_BuilderGameMode::BeginPlay()
{
	Super::BeginPlay();
    UDirector* Director = NewObject<UDirector>();

    int32 TipoDefensa = FMath::RandRange(0, 1);

    AActor* BuilderActor = nullptr;

    if (TipoDefensa == 0)
    {
        BuilderActor = GetWorld()->SpawnActor<ADefensaAntiguaBuilder>();
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Defensa Antigua seleccionada"));
    }
    else
    {
        BuilderActor = GetWorld()->SpawnActor<ADefensaFuturistaBuilder>();
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Defensa Futurista seleccionada"));
    }

    IDefenderInterface* BuilderInterface = Cast<IDefenderInterface>(BuilderActor);
    if (BuilderInterface)
    {
        Director->SelectBuilder(BuilderInterface);
    }
    else
    {
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ERROR: El Builder no implementa la interfaz DefenderInterface."));
        return;
    }

    ADefensaConfiguration* Defensa = GetWorld()->SpawnActor<ADefensaConfiguration>();
    if (!Defensa)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ERROR: No se pudo crear DefensaConfiguration."));
        return;
    }

    Defensa->CantidadTorretas = 3;
    Defensa->CantidadMinas = 2;
    Defensa->CantidadMorteros = 1;

    Director->SetDefensaConfiguration(Defensa);
    Director->Make();
}
