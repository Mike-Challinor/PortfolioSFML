#pragma once

#include <iostream>

//SFML libraries
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class MainMenu
{
private:
	
	//Variables

	//Shapes
	sf::RectangleShape playButton;
	sf::RectangleShape quitButton;

	//Window
	
	sf::VideoMode videoMode;

	//Mouse Positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Text
	sf::Text titleText;
	sf::Text playButtonText;
	sf::Text quitButtonText;

	//Fonts
	
	sf::Font* fontPointer;

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

	

public:

	//Constructors and Destructors
	MainMenu();
	~MainMenu();

	//Accessors
	const bool applicationRunning() const;
	const bool mainMenuRunning() const;
	const bool boxClickerLaunched() const;
	sf::Vector2f getMousePos();

	//Functions
	void pollEvents();

	//Updates
	void update();
	void updateGUI();
	void updateMousePosition();

	//Renders
	void render();
	void renderGUI(sf::RenderTarget* target);


	sf::Font font;
	sf::RenderWindow* window;
};

