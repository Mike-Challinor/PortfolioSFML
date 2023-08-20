#include "LeaderboardMenu.h"

void LeaderboardMenu::scoreSorting(std::vector<std::pair<std::string, unsigned>>& scoreVec, std::map<std::string, unsigned> scores)
{
	//Clear the vector
	scoreVec.clear();

	//Convert map data to a vector of pairs
	scoreVec.assign(scores.begin(), scores.end());

	//Sort the scores within the vector in descending order
	std::sort(scoreVec.begin(), scoreVec.end(),
		[](const auto& a, const auto& b) {
			return a.second > b.second;
		});

	//Delete everything but the first 10 scores
	if (scoreVec.size() > 10)
	{
		scoreVec.erase(scoreVec.begin() + 10, scoreVec.end());
	}

	std::cout << "The sorted size of Box clicker scores is: " << scoreVec.size() << std::endl;
}

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
		std::cout << "ERROR::LEADERBOARDMENU::READSCORES:: No game scores to read" << std::endl;
		break;

	case BOXCLICKER:

		std::cout << "TASK::LEADERBOARDMENU::READSCORES:: Reading box clicker scores" << std::endl;

		//Open the file
		this->inFile.open("Resources/Data/BoxClickerScores.txt", std::ios::in);

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

			std::cout << "There are " << this->boxClickerScores.size() << " scores stored" << std::endl;;

			//Sort the scores
			this->sortScores(gameNum);
		}

		break;

	case BALLSWAG:

		//Open the file
		this->inFile.open("Resources/Data/BallSwagScores.txt", std::ios::in);

		//Check if file is open
		if (this->inFile.is_open())
		{
			//Loop through all scores
			while (this->inFile >> this->name >> this->score)
			{
				//Check if score is higher than the one stored
				if (this->score > this->ballSwagScores[this->name])
				{
					//Store the score
					this->ballSwagScores[this->name] = this->score;

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
		std::cout << "TASK::LEADERBOARDMENU::SORTSCORES::Sorting BoxClicker scores" << std::endl;
		this->scoreSorting(this->boxClickerScoreVec, this->boxClickerScores);
		break;

	case BALLSWAG:
		std::cout << "TASK::LEADERBOARDMENU::SORTSCORES::Sorting BallSwag scores" << std::endl;
		this->scoreSorting(this->ballSwagScoreVec, this->ballSwagScores);
		break;
		
	}
}

void LeaderboardMenu::printScores(int gameNum)
{
	int count = 0;

	switch (gameNum)
	{
	case DEFAULT: 

		std::cout << "No game to read" << std::endl;
		break;

	case BOXCLICKER:
		std::cout << "Printing box clicker scores" << std::endl;

		for (const auto& pair : this->boxClickerScoreVec)
		{
			std::cout << pair.first << " " << pair.second << std::endl;

			count++;

			if (count > 10)
			{
				break;
			}

		}
		break;

	case BALLSWAG:

		for (const auto& pair : this->ballSwagScoreVec)
		{
			std::cout << pair.first << " " << pair.second << std::endl;

			count++;

			if (count > 10)
			{
				break;
			}

		}
		break;
	}

}

std::vector<std::pair<std::string, unsigned>> LeaderboardMenu::getScores(int gameNum)
{
	switch (gameNum)
	{
	case 0:
		break;

	case 1: 
		return this->boxClickerScoreVec;
		break;

	case 2:
		return this->ballSwagScoreVec;
		break;
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
