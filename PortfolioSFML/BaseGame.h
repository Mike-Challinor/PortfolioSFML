#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "GameState.h"
#include "PostGameMenu.h"

#include "Leaderboards.h"

class BaseGame
{
protected:
	//CLASSES
	PostGameMenu* postGameMenu;
	Leaderboards* leaderboard;

	//Window
	sf::VideoMode screenBounds;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font;

	//Game logic
	bool endGame;
	bool mouseHeld;

	//BOOLS
	bool isPostGame;
	bool hasScores;
	bool addingScore;

	//INTS
	int gameNum = 0;
	unsigned points;

	//VECTORS
	std::vector<std::pair<std::string, unsigned>> scores;


	//PROTECTED FUNCTIONS
	void initVar(sf::VideoMode screen_bounds, Leaderboards* leader_board);
	virtual void initGameVars();
	void initFonts(sf::Font font);
	virtual void initText();
	virtual void restartGame();
	void callPostGame();

public:
	//CONSTRUCTORS AND DESTRUCTORS
	BaseGame();
	~BaseGame();

	//PUBLIC FUNCTIONS
	virtual void initGame(sf::Font font, sf::VideoMode screen_bounds, Leaderboards* leader_board);
	void updateMousePositions(sf::Vector2f mousePos);
	void removeChar();

	//ACCESSORS
	const bool getEndGame() const;
	const unsigned getScore() const;
	const bool getAddingScore() const;
	const bool textFieldInFocus() const;
	const bool getIsPostGame() const;

	//MODIFIERS
	void addChar(char character);
	void setAddingScore(bool isAddingScore);
	void setEndGame(bool end_game);
	void setTextFieldFocus(bool in_focus);
	void setLeaderboard(Leaderboards* leaderboard);
	void setScoreEntered(bool score_entered);
	void setScores(std::vector<std::pair<std::string, unsigned>> scores_vec);

	//UPDATES
	virtual void update();
	void updateGame(sf::Vector2f mousePos);

	//RENDERS
	void renderGame(sf::RenderTarget& target);
	virtual void render(sf::RenderTarget& target);
};

