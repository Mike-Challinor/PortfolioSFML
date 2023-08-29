#include "Connect4.h"

//CONSTRUCTORS AND DESTRUCTORS

void Connect4::initGameVars()
{
	this->gameNum = 3;
	
	//Game logic
	this->currentPlayer = 1;
}

void Connect4::initText()
{
	this->playerText.setFillColor(sf::Color::White);
	this->playerText.setCharacterSize(48);
	this->playerText.setString("Player 1");
	this->playerText.setPosition(this->screenBounds.width / 2 - this->playerText.getGlobalBounds().width / 2, 10.f);
}

void Connect4::initBoard()
{
	this->gameBoard.initBoard();
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
	this->initFonts(font);
	this->initText();
	this->initBoard();
}

void Connect4::update()
{
	
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

	this->playerText.setPosition(this->screenBounds.width / 2 - this->playerText.getGlobalBounds().width / 2, 10.f);
}

//RENDERS

void Connect4::render(sf::RenderTarget& target)
{
	this->renderCounters(target);
	this->renderBoard(target);
}

void Connect4::renderBoard(sf::RenderTarget& target)
{
	this->gameBoard.render(target);
}

void Connect4::renderCounters(sf::RenderTarget& target)
{

}
