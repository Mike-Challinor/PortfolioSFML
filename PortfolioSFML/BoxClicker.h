#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/*
* Class that acts as the game engine.
* Wrapper class
*/

class BoxClicker
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event e;

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

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Private functions
	void initVar();
	void initWindow();
	void initFonts();
	void initText();
	void initEnemies();

public:
	//Constructors & Destructors
	BoxClicker();
	virtual ~BoxClicker();

	//Accessors
	const bool running() const;
	const bool getEndGame() const;

	//Functions

	void spawnEnemy();

	void pollEvents();
	void updateMousePositions();

	//Updates
	void update();
	void updateText();
	void updateEnemies();

	//Renders
	void render();
	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
};

