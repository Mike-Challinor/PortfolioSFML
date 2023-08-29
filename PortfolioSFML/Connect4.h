#pragma once

#include <string>

#include "BaseGame.h"
#include "Board.h"

class Connect4 : public BaseGame
{
private:

	Board gameBoard;

	//INTS
	int currentPlayer;

	//STRINGS
	std::string playerString;

	//TEXT
	sf::Text playerText;

	//PRIVATE FUNCTIONS
	void initGameVars() override;
	void initText();
	void initBoard();

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

	//RENDERS
	void render(sf::RenderTarget& target) override;
	void renderBoard(sf::RenderTarget& target);
	void renderCounters(sf::RenderTarget& target);

};

