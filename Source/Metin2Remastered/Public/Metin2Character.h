#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Metin2Character.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * Base Character class for all Metin2 playable characters.
 * Provides movement, combat stats, and Enhanced Input integration.
 */
UCLASS(Abstract)
class METIN2REMASTERED_API AMetin2Character : public ACharacter
{
	GENERATED_BODY()

public:
	AMetin2Character();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	// --- Enhanced Input ---
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> AttackAction;

	// --- Combat Stats ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxHealth = 100.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Stats")
	float CurrentHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxMana = 100.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Stats")
	float CurrentMana = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float AttackPower = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Defense = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MoveSpeed = 600.0f;

	// --- Input Handlers ---
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartAttack(const FInputActionValue& Value);

	// --- Combat ---
	UFUNCTION(BlueprintCallable, Category = "Combat")
	virtual void PerformAttack();

	UFUNCTION(BlueprintCallable, Category = "Combat")
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	bool IsAlive() const { return CurrentHealth > 0.0f; }

	UFUNCTION(BlueprintCallable, Category = "Stats")
	float GetHealthPercent() const { return MaxHealth > 0.0f ? CurrentHealth / MaxHealth : 0.0f; }

	UFUNCTION(BlueprintCallable, Category = "Stats")
	float GetManaPercent() const { return MaxMana > 0.0f ? CurrentMana / MaxMana : 0.0f; }
};
