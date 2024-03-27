// Fill out your copyright notice in the Description page of Project Settings.


#include "Avatar.h"

// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

float AAvatar::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Health -= DamageAmount;
	UE_LOG(LogTemp, Warning, TEXT("Took %f damage"), DamageAmount);
	UE_LOG(LogTemp, Warning, TEXT("Health: %f/%f"), Health, MaxHealth);

	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

int AAvatar::GetPercent(float _CurrentHealth, float _MaxHealth)
{
	return (_CurrentHealth / _MaxHealth) * 100;
}

void AAvatar::Interact()
{
	OnInteract.Broadcast();
}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	MaxHealth = 100;
	Health = MaxHealth;

	UE_LOG(LogTemp, Warning, TEXT("Health: %f/%f"), Health, MaxHealth);
	UE_LOG(LogTemp, Warning, TEXT("%d percent"), GetPercent(Health, MaxHealth));
}

bool AAvatar::IsDead() const
{
	return Health <= 0;
}

// Called every frame
void AAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

