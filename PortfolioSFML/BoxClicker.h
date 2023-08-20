#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "BaseGame.h"

#include "GameState.h"
#include "PostGameMenu.h"

#include "Leaderboards.h"

/*
* Class that acts as the game engine.
* Wrapper class
*/

class BoxClicker : public BaseGame
{
private:

	//Text
	sf::Text uiText;

	//Game logic
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Private functions
	void initGameVars() override;
	void initFonts(sf::Font font);
	void initText();
	void initEnemies();

	void restartGame() override;

public:
	//Constructors & Destructors
	BoxClicker();
	virtual ~BoxClicker();

	//PUBLIC FUNCTIONS

	void initGame(sf::Font font, sf::VideoMode screen_bounds, Leaderboards* leader_board) override;
	void spawnEnemy();

	//Updates
	void update() override;
	void updateText();
	void updateEnemies();

	//Renders
	void render(sf::RenderTarget& target) override;
	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
};

