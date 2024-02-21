// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetDummy.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATargetDummy::ATargetDummy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float ATargetDummy::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Took %f damage"), DamageAmount);
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

// Called when the game starts or when spawned
void ATargetDummy::BeginPlay()
{
	Super::BeginPlay();
	float BaseDamage = FMath::RandRange(10.0f, 40.0f);
	UGameplayStatics::ApplyDamage(this, BaseDamage, nullptr, this, UDamageType::StaticClass());
	
}

// Called every frame
void ATargetDummy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATargetDummy::Test()
{
}

