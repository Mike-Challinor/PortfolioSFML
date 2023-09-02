#include "Connect4.h"

//CONSTRUCTORS AND DESTRUCTORS

void Connect4::initGameVars()
{
	this->gameNum = 3;
	
	//Game logic
	this->currentPlayer = 1;
	this->currentTilePos = 0;
	this->isSwappingPlayer = false;

	this->counters.reserve(50);
}

void Connect4::initTextures()
{
	//Load counter texture
	if (!this->texture.loadFromFile("Resources/Textures/counter.png"))
	{
		std::cout << "ERROR::CONNECT4::INITTEXTURES:: Failed to load counter.png" << std::endl;
	}
}

void Connect4::initText()
{
	this->playerText.setFont(this->font);
	this->playerText.setFillColor(sf::Color::White);
	this->playerText.setCharacterSize(24);
	this->playerText.setString("PLACEHOLDER");
	this->playerText.setPosition(this->screenBounds.width / 2 - this->playerText.getGlobalBounds().width / 2, 10.f);
}

void Connect4::initBoard()
{
	this->gameBoard.initBoard();
}

void Connect4::spawnCounter()
{
	this->counters.push_back(Counter());
	this->counters.back().initCounter(this->currentPlayer, this->texture);

	sf::FloatRect tileBounds = this->gameBoard.getTileBounds(this->currentTilePos);
	this->counters.back().setPosition(tileBounds.left + tileBounds.width / 2 - this->counters.back().getBounds().width / 2);
}

void Connect4::swapPlayer()
{
	this->isSwappingPlayer = false;

	//Reset the current tile pos back to 0
	this->currentTilePos = 0;

	//Swap to the opposite player
	if (this->currentPlayer == 1)
	{
		this->currentPlayer = 2;
	}

	else if (this->currentPlayer == 2)
	{
		this->currentPlayer = 1;
	}

	//Spawn the next counter
	this->spawnCounter();

}

Connect4::Connect4()
{

}

Connect4::~Connect4()
{

}

//PUBLIC FUNCTIONS

void Connect4::initGame(sf::Font font, sf::VideoMode screen_bounds, Leaderboards* leader_board)
{
	this->initVar(screen_bounds, leader_board);
	this->initTextures();
	this->initFonts(font);
	this->initText();
	this->initBoard();
	this->spawnCounter();
}

void Connect4::update()
{
	this->updateInput();
	this->updateText();

	//Update the counters
	for (auto& counter : counters)
	{
		counter.update();
	}

	if (this->isSwappingPlayer && this->swapPlayerTimer.getElapsedTime().asSeconds() >= 0.2f)
	{
		this->swapPlayer();
	}
}

void Connect4::updateCounters()
{

}

void Connect4::updateText()
{
	if (this->currentPlayer == 1)
	{
		this->playerString = "Player 1";
	}

	else if (this->currentPlayer == 2)
	{
		this->playerString = "Player 2";
	}

	this->playerText.setString(this->playerString);
	this->playerText.setPosition(this->screenBounds.width / 2 - this->playerText.getGlobalBounds().width / 2, 10.f);
}

void Connect4::updateInput()
{
	//Keyboard input

	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->counters.back().getIsReleased() == false && this->currentTilePos != 0 && this->counterMoveTimer.getElapsedTime().asSeconds() >= 0.3f)
	{
		//Restart move timer
		this->counterMoveTimer.restart();

		//Decrement to the previous tile position
		this->currentTilePos--;

		//Set the current tile
		sf::FloatRect tileBounds = this->gameBoard.getTileBounds(this->currentTilePos);

		//Set position of the last counter to be spawned (controlled).
		this->counters.back().setPosition(tileBounds.left + tileBounds.width / 2 - this->counters.back().getBounds().width / 2);
	}

	//Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->counters.back().getIsReleased() == false && this->currentTilePos != 6 && this->counterMoveTimer.getElapsedTime().asSeconds() >= 0.3f)
	{
		//Restart move timer
		this->counterMoveTimer.restart();

		//Increment to the next tile position
		this->currentTilePos++;

		//Set the current tile
		sf::FloatRect tileBounds = this->gameBoard.getTileBounds(this->currentTilePos);

		//Set position of the last counter to be spawned (controlled).
		this->counters.back().setPosition(tileBounds.left + tileBounds.width / 2 - this->counters.back().getBounds().width / 2);
	}

	//Selected column
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && this->counters.back().getIsMoving() == false && this->gameBoard.isTileEmpty(this->currentTilePos) && this->counterMoveTimer.getElapsedTime().asSeconds() >= 0.3f)
	{
		//Restart move timer
		this->counterMoveTimer.restart();

		//Set the target tiles bounds
		sf::FloatRect tile_bounds = this->gameBoard.addCounter(this->currentTilePos, this->currentPlayer);

		//Set the counter to move and pass through the target location
		this->counters.back().setMoving(tile_bounds.top + tile_bounds.height / 2 - this->counters.back().getBounds().height / 2);

		this->counters.back().setIsReleased(true);

		//Check for win
		if (this->gameBoard.checkWin())
		{
			//Player has won
		}

		else
		{
			//Swap player
			this->swapPlayerTimer.restart();
			this->isSwappingPlayer = true;
		}
		
	}
}

//RENDERS

void Connect4::render(sf::RenderTarget& target)
{
	this->renderCounters(target);
	this->renderBoard(target);
	this->renderText(target);
}

void Connect4::renderBoard(sf::RenderTarget& target)
{
	this->gameBoard.render(target);
}

void Connect4::renderCounters(sf::RenderTarget& target)
{
	for (const auto &counter : this->counters)
	{
		counter.render(target);
	}
}

void Connect4::renderText(sf::RenderTarget& target)
{
	target.draw(this->playerText);
}
