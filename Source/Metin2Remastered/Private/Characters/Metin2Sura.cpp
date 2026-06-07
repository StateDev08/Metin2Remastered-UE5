#include "Characters/Metin2Sura.h"
#include "GameFramework/CharacterMovementComponent.h"

AMetin2Sura::AMetin2Sura()
{
	// Sura defaults — balanced between magic and melee
	MaxHealth = 150.0f;
	CurrentHealth = 150.0f;
	MaxMana = 200.0f;
	CurrentMana = 200.0f;
	AttackPower = 12.0f;
	Defense = 6.0f;
	MoveSpeed = 580.0f;
}

void AMetin2Sura::BeginPlay()
{
	Super::BeginPlay();
}

void AMetin2Sura::PerformAttack()
{
	if (bIsCasting || !IsAlive())
	{
		return;
	}

	// Sura can either melee or cast depending on mana
	if (HasEnoughMana(ManaCostPerSpell))
	{
		CastSpell();
	}
}

void AMetin2Sura::CastSpell()
{
	if (!HasEnoughMana(ManaCostPerSpell) || bIsCasting)
	{
		return;
	}

	bIsCasting = true;
	ConsumeMana(ManaCostPerSpell);

	if (SpellCastMontage != nullptr)
	{
		if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
		{
			AnimInstance->Montage_Play(SpellCastMontage);

			FOnMontageEnded EndDelegate;
			EndDelegate.BindLambda([this](UAnimMontage*, bool)
			{
				bIsCasting = false;
			});
			AnimInstance->Montage_SetEndDelegate(EndDelegate, SpellCastMontage);
		}
	}
	else
	{
		bIsCasting = false;
	}
}

void AMetin2Sura::ConsumeMana(float Amount)
{
	CurrentMana = FMath::Clamp(CurrentMana - Amount, 0.0f, MaxMana);
}

void AMetin2Sura::RegenerateMana(float Amount)
{
	CurrentMana = FMath::Clamp(CurrentMana + Amount, 0.0f, MaxMana);
}
