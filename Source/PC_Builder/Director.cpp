// Fill out your copyright notice in the Description page of Project Settings.

#include "Director.h"
#include "Engine/Engine.h"
#include "DefensaConfiguration.h"

void UDirector::SelectBuilder(IDefenderInterface* NewBuilder)
{
	if (NewBuilder)
	{
	Builder = NewBuilder;

	if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Builder seleccionado correctamente."));
	}
	else if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Builder recibido es NULL."));
	}
}

void UDirector::SetDefensaConfiguration(ADefensaConfiguration* NuevaDefensa)
{
	if (NuevaDefensa)
	{
		Defensa = NuevaDefensa;

		if (Builder)
		{
			AActor* BuilderActor = Cast<AActor>(Builder);
			if (BuilderActor)
			{
				Defensa->EstablecerBuild(BuilderActor);

				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Builder enviado a DefensaConfiguration."));
			}
			else if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("El builder no pudo ser casteado a AActor."));
			}
		}
		else if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No hay builder asignado al momento de enviar a Defensa."));
		}
	}
	else if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DefensaConfiguration es NULL."));
	}
}

void UDirector::Make()
{
	if (Builder && Defensa)
	{
		Defensa->EstablecerTorretas();
		Defensa->EstablecerMinas();
		Defensa->EstablecerMorteros();

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, TEXT("Construcción realizada por el Director."));
	}
	else if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Director no tiene Builder o DefensaConfiguration asignado."));
	}
}

void UDirector::ResetBuild()
{
	if (Defensa)
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Purple, TEXT("Reset simulado ejecutado en la defensa."));
		Builder = nullptr;
		Defensa = nullptr;
	}
	else if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Silver, TEXT("No hay defensa asignada para resetear."));
	}
}

ADefensaConfiguration* UDirector::GetConfiguracionBuilder() const
{
	return Builder->ObtenerDefensa();
}



