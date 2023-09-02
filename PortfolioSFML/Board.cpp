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
			tile.setPlayerNum(player_num);
			return tile.getBounds();
		}
	}
}

bool Board::checkWin()
{
	int currentPlayer = 0;

	//Check vertically
	for (int row = 0; row < this->numRows; ++row)
	{
		for (int col = 0; col < this->numColumns; ++col)
		{
			currentPlayer = this->boardGrid[row][col].getPlayerNum();

			if (currentPlayer != 0 && row + 3 <= this->numRows - 1)
			{
				if (currentPlayer == this->boardGrid[row + 1][col].getPlayerNum() && currentPlayer == this->boardGrid[row + 2][col].getPlayerNum() && currentPlayer == this->boardGrid[row + 3][col].getPlayerNum())
				{
					std::cout << "Vertical win!" << std::endl;
						return true;
				}
			}
		}
	}

	//Check horizontally
	for (int row = 0; row < this->numRows; ++row)
	{
		for (int col = 0; col < this->numColumns; ++col)
		{
			currentPlayer = this->boardGrid[row][col].getPlayerNum();

			if (currentPlayer != 0 && col + 3 <= this->numColumns - 1)
			{
				if (currentPlayer == this->boardGrid[row][col + 1].getPlayerNum() && currentPlayer == this->boardGrid[row][col + 2].getPlayerNum() && currentPlayer == this->boardGrid[row][col + 3].getPlayerNum())
				{
					std::cout << "Horizontal win!" << std::endl;
					return true;
				}
			}
		}
	}

	//Check diagonally top left to bottom right
	for (int row = 0; row < this->numRows; ++row)
	{
		for (int col = 0; col < this->numColumns; ++col)
		{
			currentPlayer = this->boardGrid[row][col].getPlayerNum();

			if (currentPlayer != 0 && col + 3 <= this->numColumns - 1 && row + 3 <= this->numRows)
			{
				if (currentPlayer == this->boardGrid[row + 1][col + 1].getPlayerNum() && currentPlayer == this->boardGrid[row + 2][col + 2].getPlayerNum() && currentPlayer == this->boardGrid[row + 3][col + 3].getPlayerNum())
				{
					std::cout << "Diagonal win!" << std::endl;
					return true;
				}
			}

		}
	}

	//Check diagonally bottom right to top left
	for (int row = this->numRows - 1; row >= 0; --row)
	{
		for (int col = this->numColumns - 1; col >= 0; --col)
		{
			currentPlayer = this->boardGrid[row][col].getPlayerNum();

			if (currentPlayer != 0 && row - 3 >= 0 && col - 3 >= 0)
			{
				if (currentPlayer == this->boardGrid[row - 1][col - 1].getPlayerNum() && currentPlayer == this->boardGrid[row - 2][col - 2].getPlayerNum() && currentPlayer == this->boardGrid[row - 3][col - 3].getPlayerNum())
				{
					std::cout << "Diagonal win!" << std::endl;
					return true;
				}
			}
		}
	}

	//No win condition met
	return false;

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
