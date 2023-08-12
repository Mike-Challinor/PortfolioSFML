#pragma once

#include <fstream>
#include <string>
#include <map>
#include <iostream>

class LeaderboardMenu
{
	enum Games { DEFAULT = 0, BOXCLICKER = 1 };
	std::map<std::string, unsigned> boxClickerScores;

private:

	std::ifstream inFile;

	std::string name;
	unsigned score = 0;

public:

	//CONSTRUCTORS AND DESTRUCTORS
	LeaderboardMenu();
	~LeaderboardMenu();

	//PUBLIC FUNCTIONS
	void readScores(int gameNum);
	void printScores(int gameNum);

	//MODIFIERS

	//UPDATES
	void update();

	void render();
	void renderText();
};

