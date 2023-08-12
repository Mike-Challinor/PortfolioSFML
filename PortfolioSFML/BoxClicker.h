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

/*
* Class that acts as the game engine.
* Wrapper class
*/

class BoxClicker
{
private:
	//Variables
	sf::Event e;

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

	//Text
	sf::Text uiText;

	//Game logic
	bool endGame;
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//BOOLS
	bool isPostGame;
	bool addingScore;

	//INTS
	int gameNum = 1;

	//VECTORS
	std::vector<std::pair<std::string, unsigned>> scores;

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Private functions
	void initVar(sf::VideoMode screen_bounds, Leaderboards* leader_board);
	void initFonts(sf::Font font);
	void initText();
	void initEnemies();

	void restartGame();

public:
	//Constructors & Destructors
	BoxClicker(sf::Font font, sf::VideoMode screen_bounds, Leaderboards* leader_board);
	virtual ~BoxClicker();

	//Accessors
	const bool getEndGame() const;
	const unsigned getScore() const;
	const bool getAddingScore() const;
	const bool textFieldInFocus() const;
	const bool getIsPostGame() const;

	//Modifiers
	void addChar(char character);
	void setAddingScore(bool isAddingScore);
	void setEndGame(bool end_game);
	void setTextFieldFocus(bool in_focus);
	void setLeaderboard(Leaderboards* leaderboard);
	void setScoreEntered(bool score_entered);
	void setScores(std::vector<std::pair<std::string, unsigned>> scores_vec);

	//Functions

	void spawnEnemy();
	void updateMousePositions(sf::Vector2f mousePos);
	void removeChar();

	//Updates
	void update(sf::Vector2f mousePos);
	void updateText();
	void updateEnemies();

	//Renders
	void render(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
};

