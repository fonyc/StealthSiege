// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SS_BasePickup.generated.h"

class ASS_Character;
class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class STEALTHSIEGE_API ASS_BasePickup : public AActor
{
	GENERATED_BODY()

public:
	ASS_BasePickup();

	FORCEINLINE USphereComponent* GetSphereCollision() const { return SphereCollision; }
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return Mesh; }

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor*OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category ="Pickup", meta=(DisplayName="Pickup"))
	void Pickup(ASS_Character* OwningCharacter);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> SphereCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;
	
};
