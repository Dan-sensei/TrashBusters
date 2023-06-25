// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "TrashBustersCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UInventoryComponent;
class UAnimMontage;
class USoundBase;
class UGameHUD;

UCLASS(config=Game)
class ATrashBustersCharacter : public ACharacter
{
    GENERATED_BODY()

    /** Pawn mesh: 1st person view (arms; seen only by self) */
    UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
    USkeletalMeshComponent* Mesh1P;

    /** First person camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
    UCameraComponent* FirstPersonCameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Inventory, meta=(AllowPrivateAccess="true"))
    UInventoryComponent* InventoryComponent;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess="true"))
    class UInputMappingContext* DefaultMappingContext;

    /** ACTIONS */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess="true"))
    class UInputAction* JumpAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess="true"))
    class UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess="true"))
    class UInputAction* LookAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess="true"))
    class UInputAction* CleanAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Cleaning, meta=(AllowPrivateAccess="true"))
    float CleanDistance = 100.0;

    USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
    UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

public:
    ATrashBustersCharacter();

    UFUNCTION(BlueprintImplementableEvent, Category = "Money")
    void DestroyActorWithAnimation(AActor* target);
    UFUNCTION(BlueprintCALLABLE, Category = "HUD")
    void SetHUD(UGameHUD* hud);
    
protected:
    virtual void BeginPlay();
    virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    void CleanTrash();

};

