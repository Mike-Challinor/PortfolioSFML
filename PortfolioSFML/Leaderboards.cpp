#include "Leaderboards.h"


void Leaderboards::addScore(std::string name, unsigned score, int leaderboard)
{

	std::cout << "Name: " << name << std::endl;
	std::cout << "Score: " << score << std::endl;
	std::cout << "Game Num: " << leaderboard << std::endl;

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
	}

}

//void Leaderboards::readScores()
//{
//	this->inFile.open("Data/leaderboard.txt", std::ios::out | std::ios::app);
//	
//	if (this->inFile.is_open())
//	{
//		while (this->inFile >> this->name >> this->score)
//		{
//			if (this->score > this->scores[this->name])
//			{
//				this->scores[this->name] = this->score;
//			}
//			
//		}
//
//		this->inFile.close();
//	}
//}

