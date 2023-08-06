#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class PauseMenu
{
private:

	//VIDEO MODE
	sf::VideoMode screenBounds;

	//BACKGROUND
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;

	//FONT
	sf::Font font;

	//TEXT
	sf::Text menuTitleText;
	sf::Text resumeButtonText;
	sf::Text quitButtonText;
	sf::Text optionsButtonText;

	//BUTTONS
	sf::Color buttonColour;
	sf::Color buttonHighlightedColour;
	sf::RectangleShape resumeButton;
	sf::RectangleShape quitButton;
	sf::RectangleShape optionsButton;

	//BOOLS
	bool gamePaused;
	bool mouseHeld;
	bool hasQuit;

	//PRIVATE FUNCTIONS
	void initVar(sf::VideoMode screen_bounds);
	void initBackground();
	void initFont(sf::Font font);
	void initText();
	void initButtons();


public:

	//CONSTRUCTORS AND DESTRUCTORS
	PauseMenu(sf::Font font, sf::VideoMode screen_bounds);
	~PauseMenu();

	//PUBLIC FUNCTIONS
	void menuInteraction(sf::Vector2f mouse_pos);

	//ACCESSORS
	const bool getPaused() const;
	const bool getHasQuit() const;

	//MODIFIERS
	void setPaused(bool is_paused);
	void setHasQuit(bool has_quit);

	//UPDATES
	void update(sf::Vector2f mousePos);
	void updateGUI(sf::Vector2f mousePos);

	//RENDERS
	void render(sf::RenderTarget& target);
	void renderGUI(sf::RenderTarget& target);
	void renderBackground(sf::RenderTarget& target);
	void renderButtons(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);


};

