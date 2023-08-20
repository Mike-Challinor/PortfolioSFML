#pragma once

class GameState
{
private:

	//VARIABLES

	//INTS
	int currentGameState;

	//ENUMS

	//PRIVATE FUNCTIONS
	void initGameState();

public:

	//CONSTRUCTOR
	GameState();

	//MODIFIERS
	void setCurrentGameState(int game_state);

	//ACCESSORS
	const int getCurrentGameState() const;

	enum gameStates { MAINMENU = 0, GAME = 1};

};

