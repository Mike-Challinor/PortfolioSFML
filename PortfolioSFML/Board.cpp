#include "Board.h"

void Board::initBoard()
{
	// Resize the outer vector
	this->boardGrid.resize(this->numRows);

	// Resize each inner vector
	for (int row = 0; row < this->numRows; ++row)
	{
		this->boardGrid[row].resize(this->numColumns);
	}

	//Loop through each tile
	for (int row = 0; row < this->numRows; ++row)
	{
		for (int col = 0; col < this->numColumns; ++col)
		{
			BoardTile& tile = boardGrid[row][col];
			
			float pos_x = 0;
			float pos_y = 0;

			if (col == 0)
			{
				pos_x = 28;
			}

			else
			{
				BoardTile& leftTile = boardGrid[row][col - 1];
				pos_x = leftTile.getBounds().left + leftTile.getBounds().width;
			}

			if (row == 0)
			{
				pos_y = 120;
			}

			else
			{
				BoardTile& aboveTile = boardGrid[row - 1][col];
				pos_y = aboveTile.getBounds().top + aboveTile.getBounds().height;
			}

			tile.initTile(pos_x, pos_y);
		}
	}
}

sf::FloatRect Board::addCounter(int col, int player_num)
{
	std::cout << "Add counter" << std::endl;

	//Loop backwards checking the bottom row first
	for (int row = this->numRows - 1; row >= 0; row--)
	{
		//Set the tile
		BoardTile& tile = this->boardGrid[row][col];

		//Set the tile to be filled if empty
		if (tile.getIsEmpty())
		{
			std::cout << "Row is: " << row << " Col is: " << col << std::endl;
			tile.setIsEmpty(false);
			return tile.getBounds();
		}
	}
}

//ACCESSORS

sf::FloatRect Board::getTileBounds(int current_pos)
{
	return this->boardGrid[0][current_pos].getBounds();
}

BoardTile& Board::getTile(int current_pos)
{
	return this->boardGrid[0][current_pos];
}

bool Board::isTileEmpty(int current_pos)
{
	BoardTile& tile = this->boardGrid[0][current_pos];
	return tile.getIsEmpty();
}

void Board::render(sf::RenderTarget& target)
{
	this->renderTiles(target);
}

void Board::renderTiles(sf::RenderTarget& target)
{
	//Render each tile
	for (int row = 0; row < this->numRows; ++row)
	{
		for (int col = 0; col < this->numColumns; ++col)
		{
			BoardTile& tile = this->boardGrid[row][col];
			tile.render(target);
		}
	}
}
