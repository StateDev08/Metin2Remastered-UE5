#include "Characters/Metin2Warrior.h"
#include "GameFramework/CharacterMovementComponent.h"

AMetin2Warrior::AMetin2Warrior()
{
	// Warrior defaults
	MaxHealth = 200.0f;
	CurrentHealth = 200.0f;
	AttackPower = 15.0f;
	Defense = 8.0f;
	MoveSpeed = 550.0f;
}

void AMetin2Warrior::BeginPlay()
{
	Super::BeginPlay();
}

void AMetin2Warrior::PerformAttack()
{
	if (bIsAttacking || !IsAlive())
	{
		return;
	}

	if (ComboMontages.Num() == 0)
	{
		return;
	}

	// Get the montage for the current combo index
	const int32 MontageIndex = FMath::Clamp(CurrentComboCount, 0, ComboMontages.Num() - 1);
	UAnimMontage* MontageToPlay = ComboMontages[MontageIndex];

	if (MontageToPlay == nullptr)
	{
		return;
	}

	bIsAttacking = true;
	CurrentComboCount++;

	// Play the combo animation
	if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
	{
		AnimInstance->Montage_Play(MontageToPlay);

		FOnMontageEnded EndDelegate;
		EndDelegate.BindUObject(this, &AMetin2Warrior::OnAttackMontageEnded);
		AnimInstance->Montage_SetEndDelegate(EndDelegate, MontageToPlay);
	}

	// Reset combo timer
	GetWorldTimerManager().ClearTimer(ComboResetTimerHandle);
	GetWorldTimerManager().SetTimer(ComboResetTimerHandle, this, &AMetin2Warrior::ResetCombo, ComboResetTime, false);

	// Check if combo is maxed out
	if (CurrentComboCount >= MaxComboCount)
	{
		ResetCombo();
	}
}

void AMetin2Warrior::ResetCombo()
{
	CurrentComboCount = 0;
	GetWorldTimerManager().ClearTimer(ComboResetTimerHandle);
}

void AMetin2Warrior::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	bIsAttacking = false;
}
