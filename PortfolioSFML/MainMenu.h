#pragma once

#include <iostream>

#include "GamesMenu.h"
#include "PauseMenu.h"
#include "BoxClicker.h"
#include "Leaderboards.h"
#include "TextField.h"

//SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class MainMenu
{
private:
	
	//Classes
	BoxClicker* boxClicker;
	GameState& gameState;
	GamesMenu* gamesMenu;
	PauseMenu* pauseMenu;
	Leaderboards* leaderboards;

	//Buttons
	sf::RectangleShape playButton;
	sf::RectangleShape quitButton;
	sf::Color buttonColour;
	sf::Color buttonHighlightedColour;

	//Bakcground
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;

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
	void initBackground();
	void initFont();
	void initText();
	void initButtons();
	void initSubMenus();
	void initBoxClicker();

	void mainMenuInteraction();

	//Delete function
	void endBoxClicker();

	

public:

	//Constructors and Destructors
	MainMenu(GameState& gameState);
	~MainMenu();

	//Accessors
	const bool applicationRunning() const;
	const bool mainMenuRunning() const;
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
	void updatePauseMenu();

	//Renders
	void render();
	void renderBoxClicker();
	void renderGUI(sf::RenderTarget& target);

};

