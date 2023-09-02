#pragma once

#include <iostream>

#include "GamesMenu.h"
#include "PauseMenu.h"
#include "LeaderboardMenu.h"
#include "BoxClicker.h"
#include "SwagBallGame.h"
#include "Connect4.h"
#include "Textfield.h"
#include "Leaderboards.h"

//SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class MainMenu
{
private:
	
	//Classes
	BoxClicker* boxClicker;
	SwagBallGame* ballSwag;
	Connect4* connect4;
	GameState& gameState;
	GamesMenu* gamesMenu;
	PauseMenu* pauseMenu;
	LeaderboardMenu* leaderboardMenu;
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
	int runningGame;

	//ENUMS

	//BOOLS
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
	void initBallSwag();
	void initConnect4();

	void mainMenuInteraction();
	void gameOver();
	void inGameEscapeEvent(BaseGame* game);


	

public:

	//Constructors and Destructors
	MainMenu(GameState& gameState);
	~MainMenu();

	//Accessors
	const bool applicationRunning() const;
	const bool mainMenuRunning() const;
	const sf::RenderWindow& getWindow() const;
	BoxClicker* getBoxClicker();
	bool hasGameEnded();

	//Modifiers
	void displayRender();
	void displayClear();

	//Functions
	void pollEvents();

	//Updates
	void update();
	void updateGame();
	void updateBoxClicker();
	void updateBallSwag();
	void updateConnect4();
	void updateGUI();
	void updateMousePosition();
	void updatePauseMenu();

	//Renders
	void render();
	void renderGame();
	void renderBoxClicker();
	void renderBallSwag();
	void renderConnect4();
	void renderGUI(sf::RenderTarget& target);

};

