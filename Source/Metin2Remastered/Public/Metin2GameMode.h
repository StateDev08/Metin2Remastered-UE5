#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Metin2GameMode.generated.h"

/**
 * Base Game Mode for Metin2 Remastered.
 * Handles game rules, player spawning, and match state.
 */
UCLASS()
class METIN2REMASTERED_API AMetin2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMetin2GameMode();

protected:
	virtual void BeginPlay() override;
};
