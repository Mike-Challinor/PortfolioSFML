#include "GameState.h"

void GameState::initGameState()
{
	this->currentGameState = 0;
}

GameState::GameState()
{
	this->initGameState();
}

void GameState::setCurrentGameState(int game_state)
{
	this->currentGameState = game_state;
}

const int GameState::getCurrentGameState() const
{
	return this->currentGameState;
}
