#pragma once

#include "CoreMinimal.h"
#include "Metin2Character.h"
#include "Metin2Sura.generated.h"

/**
 * Sura class — Magic/Melee hybrid character.
 * Uses dark magic abilities combined with sword attacks.
 */
UCLASS()
class METIN2REMASTERED_API AMetin2Sura : public AMetin2Character
{
	GENERATED_BODY()

public:
	AMetin2Sura();

protected:
	virtual void BeginPlay() override;

	// --- Magic System ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Magic")
	float SpellDamageMultiplier = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Magic")
	float ManaCostPerSpell = 15.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Combat|Magic")
	bool bIsCasting = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Magic")
	TObjectPtr<UAnimMontage> SpellCastMontage;

	// --- Overrides ---
	virtual void PerformAttack() override;

	// --- Magic Abilities ---
	UFUNCTION(BlueprintCallable, Category = "Combat|Magic")
	void CastSpell();

	UFUNCTION(BlueprintCallable, Category = "Combat|Magic")
	bool HasEnoughMana(float Cost) const { return CurrentMana >= Cost; }

	UFUNCTION(BlueprintCallable, Category = "Combat|Magic")
	void ConsumeMana(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void RegenerateMana(float Amount);
};
