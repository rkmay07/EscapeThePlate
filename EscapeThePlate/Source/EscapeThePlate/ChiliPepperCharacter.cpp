// Fill out your copyright notice in the Description page of Project Settings.


#include "ChiliPepperCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine/World.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AChiliPepperCharacter::AChiliPepperCharacter() : Super()
{
	// Set instance variables to defaults
	MoveSpeed = 1.5f;
	AbilityCooldown = 2.f;
	MaxJumpHeight = 500.f;
	AirControl = .1;

	GetCharacterMovement()->JumpZVelocity = MaxJumpHeight;
	GetCharacterMovement()->AirControl = AirControl;
}

// Called every frame
void AChiliPepperCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AChiliPepperCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Ability", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveY", this, &AChiliPepperCharacter::MoveY);
	PlayerInputComponent->BindAxis("MoveX", this, &AChiliPepperCharacter::MoveX);
}

// Movement in the X direction with a magnitude
void AChiliPepperCharacter::MoveX(float magnitude)
{
	if (Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, magnitude * MoveSpeed);
	}
}

// Movement in the Y direction with a magnitude
void AChiliPepperCharacter::MoveY(float magnitude)
{
	if (Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, magnitude * MoveSpeed);
	}
}

//Driver for the chili pepper's propulsion ability
void AChiliPepperCharacter::PerformAbility()
{
	Super::PerformAbility();
	Super::Jump();
}