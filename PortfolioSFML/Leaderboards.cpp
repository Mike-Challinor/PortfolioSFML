#include "Leaderboards.h"


void Leaderboards::addScore(std::string name, unsigned score, int leaderboard)
{
	switch (leaderboard)
	{
	case DEFAULT:
		std::cout << "ERROR::LEADERBOARDS::ADDSCORE:: No leaderboard selected" << std::endl;
		break;

	case BOXCLICKER:

		//Open file for box clicker scores
		this->outFile.open("Resources/Data/BoxClickerScores.txt", std::ios::out | std::ios::app);

		//Check if file is open
		if (this->outFile.is_open())
		{
			//Add box clicker score
			this->outFile << name << " " << score << std::endl;
			this->outFile.close();
		}

		else
		{
			std::cout << "ERROR::LEADERBOARDS::ADDSCORE:: BoxClickerScores.txt failed to open" << std::endl;
		}

		break;

	case BALLSWAG:

		//Open file for box clicker scores
		this->outFile.open("Resources/Data/BallSwagScores.txt", std::ios::out | std::ios::app);

		//Check if file is open
		if (this->outFile.is_open())
		{
			//Add box clicker score
			this->outFile << name << " " << score << std::endl;
			this->outFile.close();
		}

		else
		{
			std::cout << "ERROR::LEADERBOARDS::ADDSCORE:: BallSwagScores.txt failed to open" << std::endl;
		}

		break;
	}

}

