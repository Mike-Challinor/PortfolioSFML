#pragma once

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

class LeaderboardMenu
{
	enum Games { DEFAULT = 0, BOXCLICKER = 1, BALLSWAG = 2};

private:

	std::ifstream inFile;

	std::string name;
	unsigned score = 0;


	std::map<std::string, unsigned> boxClickerScores;
	std::vector<std::pair<std::string, unsigned>> boxClickerScoreVec;

	std::map<std::string, unsigned> ballSwagScores;
	std::vector<std::pair<std::string, unsigned>> ballSwagScoreVec;

	//PRIVATE FUNCTIONS
	void scoreSorting(std::vector<std::pair<std::string, unsigned>>& scoreVec, std::map<std::string, unsigned> scores);

public:

	//CONSTRUCTORS AND DESTRUCTORS
	LeaderboardMenu();
	~LeaderboardMenu();

	//PUBLIC FUNCTIONS
	void readScores(int gameNum);
	void sortScores(int gameNum);
	void printScores(int gameNum);

	//ACCESSORS
	std::vector<std::pair<std::string, unsigned>> getScores(int gameNum);

	//MODIFIERS

	//UPDATES
	void update();

	void render();
	void renderText();
};

