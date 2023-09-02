#pragma once

#include <vector>

#include "BoardTile.h"

class Board
{
private:

	//CLASSES

	//INTS
	const int numColumns = 7;	//1 to 7
	const int numRows = 6;		//1 to 6

	std::vector<std::vector<BoardTile>> boardGrid;

public:

	//PUBLIC FUNCTIONS
	void initBoard();
	sf::FloatRect addCounter(int col, int player_num);
	bool checkWin();

	//ACCESSORS
	sf::FloatRect getTileBounds(int current_pos);
	BoardTile& getTile(int current_pos);
	bool isTileEmpty(int current_pos);

	//RENDERS
	void render(sf::RenderTarget& target);
	void renderTiles(sf::RenderTarget& target);
};

