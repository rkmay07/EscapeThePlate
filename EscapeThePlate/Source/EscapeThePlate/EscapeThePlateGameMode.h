// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "EscapeThePlateGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPETHEPLATE_API AEscapeThePlateGameMode : public AGameMode
{
	GENERATED_BODY()

	public:

		UPROPERTY()
		float RecordedGameTime;

		UPROPERTY(BlueprintReadOnly, Category = LevelData)
		FString LevelName;

		UPROPERTY(BlueprintReadOnly, Category = LevelData)
		float ParTime;

		UPROPERTY(BlueprintReadWrite, Category = LevelData)
		bool HasChallengeCompleted;

		UPROPERTY(BlueprintReadWrite, Category = GameStatus)
		bool bCanPlayerPause;

		UPROPERTY(BlueprintReadWrite, Category = GameObjects)
		TArray<class AIngredientBaseCharacter*> Characters;

		UPROPERTY(BlueprintReadWrite, Category = GameObjects)
		TArray<class AIngredientDeathZone*> DeathZones;

		UFUNCTION(BlueprintCallable)
		void RegisterCharacterWithGame(AIngredientBaseCharacter* Character);

		UFUNCTION(BlueprintCallable)
		void RegisterDeathZoneWithGame(AIngredientDeathZone* DeathZone);

		UFUNCTION(BlueprintCallable)
		void AutoReposessCharacter();

		UFUNCTION(BlueprintCallable)
		AIngredientDeathZone* GetClosestDeathZone(FVector ActorLocation);

		UFUNCTION(BlueprintCallable)
		void SetupLevelData(const FString& LevelSaveName, float NewParTime);

		UFUNCTION(BlueprintCallable)
		bool CheckGameOver();

		UFUNCTION(BlueprintCallable)
		uint8 GetStarsEarned();

		UFUNCTION(BlueprintCallable)
		bool DidPlayerWin();

		UFUNCTION(BlueprintCallable)
		void PossessIngredient(AIngredientBaseCharacter* Character);

		UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void CharacterPossessionChanged();

		UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void CharacterStatusChanged();

		UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void GameOver();

		UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void PauseGame();

		UFUNCTION(BlueprintCallable)
		void RecordGameTime();

		UFUNCTION(BlueprintCallable)
		float GetRecordedTime();
};
