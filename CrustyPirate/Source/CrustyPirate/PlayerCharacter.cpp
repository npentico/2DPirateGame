// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void APlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APlayerCharacter::Move(float InputValue)
{
    if (bIsAlive && bCanMove)
    {
        FVector Direction = FVector(1, 0, 0);
        AddMovementInput(Direction, InputValue);
        UpdateDirection(InputValue);
    }
}

void APlayerCharacter::JumpStarted(bool InputValue)
{
    if (bIsAlive && bCanMove)
    {
        Jump();
    }
}

void APlayerCharacter::JumpEnded(bool InputValue)
{
    StopJumping();
}

void APlayerCharacter::Attack(bool InputValue)
{
}

void APlayerCharacter::UpdateDirection(float MoveDirection)
{

    FRotator CurrentRotation = Controller->GetControlRotation();
    if (MoveDirection < 0)
    {
        if (CurrentRotation.Yaw != 180)
        {
            Controller->SetControlRotation(FRotator(CurrentRotation.Pitch, 180.0f, CurrentRotation.Roll));
        }
    }
    else if (MoveDirection > 0)
    {
        if (CurrentRotation.Yaw != 0)
        {
            Controller->SetControlRotation(FRotator(CurrentRotation.Pitch, 0, CurrentRotation.Roll));
        }
    }
}
