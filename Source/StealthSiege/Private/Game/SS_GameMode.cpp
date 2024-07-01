// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SS_GameMode.h"
#include "Game/SS_GameState.h"
#include "Player/SS_PlayerController.h"
#include "Player/SS_PlayerState.h"

ASS_GameMode::ASS_GameMode()
{
	GameStateClass = ASS_GameState::StaticClass();
	PlayerStateClass = ASS_PlayerState::StaticClass();
	PlayerControllerClass = ASS_PlayerController::StaticClass();
}
