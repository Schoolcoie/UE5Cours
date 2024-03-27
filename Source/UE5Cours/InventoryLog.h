// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryLog.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMyDelegate, const FString&, ItemName);

UCLASS()
class UE5COURS_API AInventoryLog : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryLog();

	UPROPERTY(BlueprintAssignable)
	FMyDelegate OnLootDelegate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void MyBlueprintEvent();

private:

	UFUNCTION()
	void MyFunction(const FString& ItemName);

	UFUNCTION(BlueprintCallable)
	void LootNotify(const FString& ItemName);

};
