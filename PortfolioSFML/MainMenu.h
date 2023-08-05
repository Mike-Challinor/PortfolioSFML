#pragma once

#include <iostream>

#include "BoxClicker.h"

//SFML libraries
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class MainMenu
{
private:
	
	//Classes
	BoxClicker* boxClicker;
	GameState& gameState;

	//Shapes
	sf::RectangleShape playButton;
	sf::RectangleShape quitButton;

	//Window
	sf::RenderWindow window;
	sf::VideoMode videoMode;

	//Mouse Positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Text
	sf::Text titleText;
	sf::Text playButtonText;
	sf::Text quitButtonText;

	//Fonts
	
	sf::Font font;

	//Events
	sf::Event sfmlEvent;

	//Ints
	int menu;

	//Bools
	bool mouseHeld;
	bool mainMenuOpen = true;
	bool isBoxClickerLaunched = false;

	//Init functions
	void initVar();
	void initWindow();
	void initFont();
	void initText();
	void initButtons();
	void initBoxClicker();

	void checkForLeftClick();

	//Delete function
	void endBoxClicker();

	

public:

	//Constructors and Destructors
	MainMenu(GameState& gameState);
	~MainMenu();

	//Accessors
	const bool applicationRunning() const;
	const bool mainMenuRunning() const;
	const bool boxClickerLaunched() const;
	const sf::RenderWindow& getWindow() const;
	BoxClicker* getBoxClicker();
	bool hasBoxClickerEnded();

	//Modifiers
	void displayRender();
	void displayClear();

	//Functions
	void pollEvents();

	//Updates
	void update();
	void updateBoxClicker();
	void updateGUI();
	void updateMousePosition();

	//Renders
	void render();
	void renderBoxClicker();
	void renderGUI(sf::RenderTarget& target);

};

