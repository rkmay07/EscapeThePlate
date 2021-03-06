// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IngredientBaseCharacter.h"
#include "ChiliPepperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPETHEPLATE_API AChiliPepperCharacter : public AIngredientBaseCharacter
{
	GENERATED_BODY()

public:
	AChiliPepperCharacter();

	// Jump control vars
	float MaxJumpHeight;
	float AirControl;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Movement functions
	void MoveX(float magnitude) override;
	void MoveY(float magnitude) override;

	// Ability functions
	void PerformAbility() override;

};
