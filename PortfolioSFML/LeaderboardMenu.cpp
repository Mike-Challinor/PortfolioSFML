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

			//Sort the scores
			this->sortScores(gameNum);
		}

		break;
	}

	
}

void LeaderboardMenu::sortScores(int gameNum)
{
	switch (gameNum)
	{
	case DEFAULT:
		std::cout << "ERROR::LEADERBOARDMENU::SORTSCORES::No game selected" << std::endl;
		break;

	case BOXCLICKER:
		//Clear the vector
		this->boxClickerScoreVec.clear();

		//Convert map data to a vector of pairs
		this->boxClickerScoreVec.assign(this->boxClickerScores.begin(), this->boxClickerScores.end());

		//Sort the scores within the vector in descending order
		std::sort(this->boxClickerScoreVec.begin(), this->boxClickerScoreVec.end(),
			[](const auto& a, const auto& b) {
				return a.second > b.second; 
			});

		//Delete everything but the first 10 scores
		if (this->boxClickerScoreVec.size() > 10)
		{
			this->boxClickerScoreVec.erase(this->boxClickerScoreVec.begin() + 10, this->boxClickerScoreVec.end());
		}
		
	}
}

void LeaderboardMenu::printScores(int gameNum)
{
	int count = 0;

	for (const auto& pair : boxClickerScoreVec)
	{
		std::cout << pair.first << " " << pair.second << std::endl;
		
		count++;
		
		if (count > 10)
		{
			break;
		}

	}

}

std::vector<std::pair<std::string, unsigned>> LeaderboardMenu::getScores(int gameNum)
{
	return this->boxClickerScoreVec;
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
