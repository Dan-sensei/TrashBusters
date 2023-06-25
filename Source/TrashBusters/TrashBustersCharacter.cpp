// Copyright Epic Games, Inc. All Rights Reserved.

#include "TrashBustersCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PickableTrashComponent.h"

ATrashBustersCharacter::ATrashBustersCharacter()
{
  // Set size for collision capsule
  GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
    
  // Create a CameraComponent	
  FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
  FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
  FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
  FirstPersonCameraComponent->bUsePawnControlRotation = true;
}

void ATrashBustersCharacter::BeginPlay()
{
  Super::BeginPlay();

  if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
  {
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
    {
      Subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
  }
}

void ATrashBustersCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
  if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
  {
    EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
    EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATrashBustersCharacter::Move);

    EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATrashBustersCharacter::Look);

    EnhancedInputComponent->BindAction(CleanAction, ETriggerEvent::Triggered, this, &ATrashBustersCharacter::CleanTrash);
  }
}

void ATrashBustersCharacter::Move(const FInputActionValue& Value)
{
  // input is a Vector2D
  FVector2D MovementVector = Value.Get<FVector2D>();

  if (Controller != nullptr)
  {
    AddMovementInput(GetActorForwardVector(), MovementVector.Y);
    AddMovementInput(GetActorRightVector(), MovementVector.X);
  }
}

void ATrashBustersCharacter::Look(const FInputActionValue& Value)
{
  FVector2D LookAxisVector = Value.Get<FVector2D>();

  if (Controller != nullptr)
  {
    AddControllerYawInput(LookAxisVector.X);
    AddControllerPitchInput(LookAxisVector.Y);
  }
}

void ATrashBustersCharacter::CleanTrash()
{
  FHitResult HitResult;
  FVector StartLocation = GetActorLocation();
  FVector EndLocation = StartLocation + GetActorForwardVector() * CleanDistance;
  FCollisionQueryParams TraceParams(FName(TEXT("Raycast")), false, this);

  if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, TraceParams))
  {
    AActor* hitActor = HitResult.GetActor();
    FVector hitLocation = HitResult.Location;

    if (hitActor != nullptr)
    {
      if (UPickableTrashComponent* pickableTrashComponent = Cast<UPickableTrashComponent>(hitActor->GetComponentByClass(UPickableTrashComponent::StaticClass())))
      {
        TrashType type = pickableTrashComponent->bTrashType;
        
        float score;
        switch (type)
        {
        case TrashType::TrashType_SodaCan:
        case TrashType::TrashType_PlasticBottle: score = 10; break;
        case TrashType::TrashType_GlassBottle: score = 20; break;
        case TrashType::TrashType_Paper: score = 5; break;
        default: break;
        }

        // TODO: increment score

        hitActor->Destroy();
      }
    }
  }
}
