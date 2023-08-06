#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Leaderboards
{

private:

	struct scoreEntry
	{
		std::string name;
		unsigned score;
	};

	std::ofstream outFile;
	std::ifstream inFile;

	std::string name;
	unsigned score;

	//BACKGROUND
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;

	//FONT
	sf::Font font;

	//TEXT
	sf::Text menuTitleText;
	sf::Text boxClickerTitleText;
	sf::Text backButtonText;

	//BUTTONS
	sf::Color buttonColour;
	sf::Color buttonHighlightedColour;
	sf::RectangleShape boxClickerButton;
	sf::RectangleShape backButton;
	sf::Sprite boxClickerSprite;
	sf::Texture boxClickerTexture;

	//BOOLS
	bool mouseHeld;
	bool menuOpen;

	//PRIVATE FUNCTIONS
	void initVar(sf::VideoMode screen_bounds);
	void initBackground();
	void initFont(sf::Font font);
	void initText();
	void initButtons();

public:

	//CONSTRUCTORS AND DESTRUCTORS
	Leaderboards();
	~Leaderboards();

	//PUBLIC FUNCTIONS
	void addScore(std::string name, unsigned score);
	void storeScores();
};

