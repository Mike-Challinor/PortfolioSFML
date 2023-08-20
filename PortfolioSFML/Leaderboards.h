#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Leaderboards
{
	std::map<std::string, unsigned> scores;
	enum leaderboard { DEFAULT = 0, BOXCLICKER = 1, BALLSWAG = 2};

private:

	std::ofstream outFile;

	std::string name;
	unsigned score = 0;

	//INTS
	int selectedLeaderboard = 0;


	//PRIVATE FUNCTIONS

public:

	//PUBLIC FUNCTIONS
	void addScore(std::string name, unsigned score, int leaderboard);
	/*void readScores();*/

	
};

