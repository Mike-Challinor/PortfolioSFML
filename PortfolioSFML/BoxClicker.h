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

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Private functions
	void initVar(sf::VideoMode screen_bounds);
	void initFonts(sf::Font font);
	void initText();
	void initEnemies();

	void restartGame();

public:
	//Constructors & Destructors
	BoxClicker(sf::Font font, sf::VideoMode screen_bounds);
	virtual ~BoxClicker();

	//Accessors
	const bool getEndGame() const;
	const unsigned getScore() const;
	const bool getAddingScore() const;
	bool isPostGameNull();

	//Modifiers
	void setString(char character);
	void setAddingScore(bool isAddingScore);

	//Functions

	void spawnEnemy();
	void updateMousePositions(sf::Vector2f mousePos);

	//Updates
	void update(sf::Vector2f mousePos);
	void updateText();
	void updateEnemies();

	//Renders
	void render(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
};

