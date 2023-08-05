#include <iostream>
#include "GameState.h"

void GameState::initGameState()
{
	this->currentGameState = 0;
	std::cout << "Game State = " << this->currentGameState << std::endl;
}

GameState::GameState()
{
	this->initGameState();
}

void GameState::setCurrentGameState(int game_state)
{
	this->currentGameState = game_state;
	std::cout << "Game State = " << this->currentGameState << std::endl;
}

const int GameState::getCurrentGameState() const
{
	return this->currentGameState;
}
