// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DMC4Character.h"
#include "DMC4PlayerCharacter.generated.h"

/*
 * Base class of all playable characters in DMC4Clone
 */
UCLASS()
class DMC4CLONE_API ADMC4PlayerCharacter : public ADMC4Character
{
    GENERATED_BODY()
    
public:
    // Sets default values for this character's properties
    ADMC4PlayerCharacter();
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;
    
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    
    FORCEINLINE UCameraComponent* GetThirdPersonCamera() const
    {
        return ThirdPersonCamera;
    }
    
    
private:
    //Rotates Third Person Camera around Character like orbit camera
    void RotateCamera(float value);
    
    //Moves character forward based on Third Person Camera forward vector. W for forward, S for back.
    void MoveForward(float value);
    
    //Moves character right based on Third Person Camera current right vector. D for right, A for left.
    void MoveRight(float value);
    
    //Camera Component in 3rd Person Perspective to character
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
    UCameraComponent* ThirdPersonCamera = nullptr;
    
    //Camera Boom to 3rd Person Camera
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* ThirdPersonSpringArm = nullptr;
    
    
    
};