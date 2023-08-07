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
		this->outFile << name << " " << score << std::endl;
		this->outFile.close();
	}
}

void Leaderboards::readScores()
{
	this->inFile.open("Data/leaderboard.txt", std::ios::out | std::ios::app);
	
	if (this->inFile.is_open())
	{
		while (this->inFile >> this->name >> this->score)
		{
			if (this->score > this->scores[this->name])
			{
				this->scores[this->name] = this->score;
			}
			
		}

		this->inFile.close();
	}
}

void Leaderboards::printLeaderboard() const
{
	for (const auto& pair : scores) 
	{
		std::cout << "Name: " << pair.first << ", Score: " << pair.second << '\n';
	}
}

