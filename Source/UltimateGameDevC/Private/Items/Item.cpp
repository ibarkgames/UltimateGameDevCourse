#include "Items/Item.h"
#include "UltimateGameDevC/DebugMacros.h"


AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

float AItem::TransformSin() const
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformCosin() const
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AItem::ExampleLogging()
{
	// Example log message
	UE_LOG(LogTemp, Display, TEXT("AItem::BeginPlay"));
	// Example log on screen
	if (GEngine) // it is not nullptr
	{
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, TEXT("AItem::BeginPlayHuu"));
	}

	// UE_LOG(LogTemp, Display, TEXT("DeltaTime: %f"), DeltaTime);
	// if (GEngine) // it is not nullptr
	// {
	// 	const FString Name = GetName();
	// 	const FString Message = FString::Printf(TEXT("ItemName: %s, DeltaTime: %f"), *Name, DeltaTime);
	// 	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, Message);
	// }
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	// ExampleLogging();

	
}

void AItem::ExampleMoving(const float DeltaTime)
{
	// cm/s
	const float MovementRate = 50.f;
	const float RotationRate = 45.f;
	
	// cm/s * s/frame = cm/frame
	// AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.0f, 0.0f));
	// AddActorLocalRotation(FRotator(RotationRate * DeltaTime, 0.0f, 0.0f));

	// SetActorLocation(FVector(2270, -5480, 910 + 100));
	// SetActorRotation(FRotator(0, 0, 45), ETeleportType::TeleportPhysics);
	
	AddActorWorldOffset(FVector(0.0f, 0.0f, TransformSin()));
	DRAW_DEBUG_SPHERE_SINGLE_FRAME(GetActorLocation());
	DRAW_DEBUG_VECTOR_SINGLE_FRAME(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ExampleMoving(DeltaTime);
	RunningTime += DeltaTime;
	
}


