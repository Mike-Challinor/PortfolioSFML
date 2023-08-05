#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class GamesMenu
{
private:

	//VIDEO MODE
	sf::VideoMode screenBounds;

	//FONT
	sf::Font font;

	//TEXT
	sf::Text menuTitleText;
	sf::Text boxClickerTitleText;
	sf::Text backText;

	//BUTTONS
	sf::RectangleShape boxClickerButton;
	sf::RectangleShape backButton;
	sf::Sprite boxClickerImage;

	//BOOLS
	bool mouseHeld;
	bool menuOpen;
	bool boxClickerLaunched;

	//PRIVATE FUNCTIONS
	void initVar(sf::VideoMode screen_bounds);
	void initFont(sf::Font font);
	void initText();
	void initButtons();

public:

	//CONSTRUCTORS AND DESTRUCTORS
	GamesMenu(sf::Font font, sf::VideoMode screen_bounds);
	~GamesMenu();

	//PUBLIC FUNCTIONS
	void menuInteraction(sf::Vector2f mouse_pos);

	//ACCESSORS
	const bool getMenuOpen() const;

	//MODIFIERS
	void setMenuOpen(bool is_open);

	//UPDATES
	void update();

	//RENDERS
	void render(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
};

