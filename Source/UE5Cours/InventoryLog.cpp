// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryLog.h"

// Sets default values
AInventoryLog::AInventoryLog()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInventoryLog::BeginPlay()
{
	Super::BeginPlay();

	OnLootDelegate.AddDynamic(this, &AInventoryLog::MyFunction);
	
}

void AInventoryLog::MyFunction(const FString& ItemName)
{
	UE_LOG(LogTemp, Warning, TEXT("Item Name: %s"), *ItemName);

	MyBlueprintEvent();
}

void AInventoryLog::LootNotify(const FString& ItemName)
{
	// Broadcast Delegate
	OnLootDelegate.Broadcast(ItemName);

	// Remove MyFunction from Delegate
	OnLootDelegate.RemoveAll(this);
	//OnLootDelegate.RemoveDynamic(this, &AInventoryLog::MyFunction);
}
