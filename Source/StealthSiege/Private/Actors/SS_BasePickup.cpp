// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SS_BasePickup.h"
#include "Character/SS_Character.h"
#include "Components/SphereComponent.h"


// Sets default values
ASS_BasePickup::ASS_BasePickup()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollider");
	RootComponent = SphereCollision;
	SphereCollision->SetGenerateOverlapEvents(true);
	SphereCollision->SetSphereRadius(150.f);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(SphereCollision);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ASS_BasePickup::BeginPlay()
{
	Super::BeginPlay();

	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ASS_BasePickup::OnBeginOverlap);
}

void ASS_BasePickup::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ASS_Character* Character = Cast<ASS_Character>(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(2, 5.f, FColor::Blue,TEXT("Pickup!"));
		Pickup(Character);
	}
}

void ASS_BasePickup::Pickup_Implementation(ASS_Character* OwningCharacter)
{
	SetOwner(OwningCharacter);
}
