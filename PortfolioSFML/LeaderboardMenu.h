#pragma once

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

class LeaderboardMenu
{
	enum Games { DEFAULT = 0, BOXCLICKER = 1 };

private:

	std::ifstream inFile;

	std::string name;
	unsigned score = 0;


	std::map<std::string, unsigned> boxClickerScores;
	std::vector<std::pair<std::string, unsigned>> boxClickerScoreVec;

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

