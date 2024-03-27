// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlate.h"

// Sets default values
APressurePlate::APressurePlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APressurePlate::BeginPlay()
{
	Super::BeginPlay();
	
}

void APressurePlate::BindEvent(AAvatar* other)
{
	other->OnInteract.AddDynamic(this, &APressurePlate::Activate);
}

void APressurePlate::UnbindEvents(AAvatar* other)
{
	other->OnInteract.RemoveAll(this);
}

// Called every frame
void APressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APressurePlate::Activate()
{
	UE_LOG(LogTemp, Warning, TEXT("It works!"));
	//Interface stuff, this function gets binded to the Avatar's delegate
}


