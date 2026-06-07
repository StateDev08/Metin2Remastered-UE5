#pragma once

#include "CoreMinimal.h"
#include "Metin2Character.h"
#include "Metin2Warrior.generated.h"

/**
 * Warrior class — Melee-focused character with combo attacks.
 * Uses One-Hand Sword combo system with multiple attack levels.
 */
UCLASS()
class METIN2REMASTERED_API AMetin2Warrior : public AMetin2Character
{
	GENERATED_BODY()

public:
	AMetin2Warrior();

protected:
	virtual void BeginPlay() override;

	// --- Combo System ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Combo")
	int32 MaxComboCount = 7;

	UPROPERTY(BlueprintReadOnly, Category = "Combat|Combo")
	int32 CurrentComboCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Combo")
	float ComboResetTime = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Combo")
	TArray<TObjectPtr<UAnimMontage>> ComboMontages;

	UPROPERTY(BlueprintReadOnly, Category = "Combat|Combo")
	bool bIsAttacking = false;

	// --- Warrior Stats ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats|Warrior")
	float ComboMultiplier = 1.2f;

	// --- Overrides ---
	virtual void PerformAttack() override;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void ResetCombo();

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

private:
	FTimerHandle ComboResetTimerHandle;
};
