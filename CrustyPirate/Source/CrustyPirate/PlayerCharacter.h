// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"


#include "PlayerCharacter.generated.h"

/**
 *
 */
UCLASS()
class CRUSTYPIRATE_API APlayerCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USpringArmComponent *SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent *Camera;
	UFUNCTION(BlueprintCallable)
	void Move(float InputValue);

	void UpdateDirection(float MoveDirection);

	UFUNCTION(BlueprintCallable)
	void JumpStarted(bool InputValue);

	UFUNCTION(BlueprintCallable)
	void JumpEnded(bool InputValue);

	UFUNCTION(BlueprintCallable)
	void Attack(bool InputValue);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsAlive = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bCanMove = true;
};
