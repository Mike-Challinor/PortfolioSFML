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
	sf::Event e;

	//Window
	sf::RenderTarget* window;

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
	void initFonts(sf::Font font);
	void initText();
	void initEnemies();

public:
	//Constructors & Destructors
	BoxClicker(sf::Font font);
	virtual ~BoxClicker();

	//Accessors
	const bool getEndGame() const;

	//Modifiers
	void setWindow(sf::RenderTarget* window);

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

