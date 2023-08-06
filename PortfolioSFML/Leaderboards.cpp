#include "Leaderboards.h"

void Leaderboards::initVar(sf::VideoMode screen_bounds)
{

}

void Leaderboards::initBackground()
{
}

void Leaderboards::initFont(sf::Font font)
{
}

void Leaderboards::initText()
{
}

void Leaderboards::initButtons()
{
}

Leaderboards::Leaderboards()
{

}

Leaderboards::~Leaderboards()
{

}

void Leaderboards::addScore(std::string name, unsigned score)
{
	this->outFile.open("Data/leaderboard.txt", std::ios::out | std::ios::app);

	if (this->outFile.is_open())
	{
		this->outFile << name << std::endl << score << std::endl << std::endl;
	}
}

void Leaderboards::storeScores()
{
	int entryNum = 1;

	while (this->inFile >> name >> score)
	{

	}
}
