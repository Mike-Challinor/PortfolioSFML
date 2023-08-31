#pragma once

#include <string>

#include "BaseGame.h"
#include "Board.h"
#include "Counter.h"

class Connect4 : public BaseGame
{
private:

	//CLASSES
	Board gameBoard;

	//TEXTURES
	sf::Texture texture;

	//VECTORS
	std::vector<Counter> counters;

	//TIMERS
	sf::Clock counterMoveTimer;
	sf::Clock swapPlayerTimer;

	//INTS
	int currentPlayer;
	int currentTilePos;

	//BOOLS
	bool isSwappingPlayer;

	//STRINGS
	std::string playerString;

	//TEXT
	sf::Text playerText;

	//PRIVATE FUNCTIONS
	void initGameVars() override;
	void initTextures();
	void initText();
	void initBoard();

	void spawnCounter();
	void swapPlayer();

public:

	//CONSTRUCTORS AND DESTRUCTORS
	Connect4();
	virtual ~Connect4();

	//PUBLIC FUNCTIONS
	void initGame(sf::Font font, sf::VideoMode screen_bounds, Leaderboards* leader_board) override;

	//UPDATES
	void update() override;
	void updateCounters();
	void updateText();
	void updateInput();

	//RENDERS
	void render(sf::RenderTarget& target) override;
	void renderBoard(sf::RenderTarget& target);
	void renderCounters(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);

};

