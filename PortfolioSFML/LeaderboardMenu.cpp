#include "LeaderboardMenu.h"

LeaderboardMenu::LeaderboardMenu()
{
}

LeaderboardMenu::~LeaderboardMenu()
{
}

void LeaderboardMenu::readScores(int gameNum)
{

	switch (gameNum)
	{
	case DEFAULT:
		std::cout << "ERROR::LEADERBOARDMENU::READSCORES:: No game selected" << std::endl;
		break;

	case BOXCLICKER:

		//Open the file
		this->inFile.open("Resources/Data/BoxClickerScores.txt", std::ios::out | std::ios::app);

		//Check if file is open
		if (this->inFile.is_open())
		{
			//Loop through all scores
			while (this->inFile >> this->name >> this->score)
			{
				//Check if score is higher than the one stored
				if (this->score > this->boxClickerScores[this->name])
				{
					//Store the score
					this->boxClickerScores[this->name] = this->score;
				}

			}

			//Close the file
			this->inFile.close();
		}

		break;
	}

	
}

void LeaderboardMenu::printScores(int gameNum)
{
	for (const auto& pair : boxClickerScores)
	{
		std::cout << "Name: " << pair.first << " = " << pair.second << std::endl;
	}
}

void LeaderboardMenu::update()
{
}

void LeaderboardMenu::render()
{
}

void LeaderboardMenu::renderText()
{

}
