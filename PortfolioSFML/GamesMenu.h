#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "BaseGameThumbnails.h"

class GamesMenu
{
private:

	//CLASSES
	BaseGameThumbnails* boxClickerThumbnail;
	BaseGameThumbnails* ballSwagThumbnail;
	BaseGameThumbnails* connect4Thumbnail;

	//VIDEO MODE
	sf::VideoMode screenBounds;

	sf::Clock menuOpenedTimer;

	//BACKGROUND
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;

	//FONT
	sf::Font font;

	//TEXT
	sf::Text menuTitleText;
	sf::Text boxClickerTitleText;
	sf::Text backButtonText;

	//BUTTONS
	sf::Color buttonColour;
	sf::Color buttonHighlightedColour;
	sf::RectangleShape backButton;

	//VECTORS
	std::vector<BaseGameThumbnails*> thumbnails;

	//INT
	int gameLaunched = 0;

	//ENUM
	enum launchedGame {DEFAULT = 0, BOXCLICKER = 1, BALLSWAG = 2, CONNECT4 = 3};

	//BOOLS
	bool mouseHeld;
	bool menuOpen;
	bool spriteEnlarging;
	bool spriteShrinking;

	//PRIVATE FUNCTIONS
	void initVar(sf::VideoMode screen_bounds);
	void initBackground();
	void initFont(sf::Font font);
	void initText();
	void initButtons();

public:

	//CONSTRUCTORS AND DESTRUCTORS
	GamesMenu(sf::Font font, sf::VideoMode screen_bounds);
	virtual ~GamesMenu();

	//PUBLIC FUNCTIONS
	void menuInteraction(sf::Vector2f mouse_pos);

	//ACCESSORS
	const bool getMenuOpen() const;
	const int getGameLaunched() const;

	//MODIFIERS
	void setMenuOpen(bool is_open);
	void setGameLaunched(int game_launched);

	//UPDATES
	void update(sf::Vector2f mousePos);
	void updateGUI(sf::Vector2f mousePos);

	//RENDERS
	void render(sf::RenderTarget& target);
	void renderGUI(sf::RenderTarget& target);
	void renderBackground(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void renderButtons(sf::RenderTarget& target);
};

