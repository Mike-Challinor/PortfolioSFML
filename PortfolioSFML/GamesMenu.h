#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class GamesMenu
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
	sf::Text boxClickerTitleText;
	sf::Text backButtonText;

	//BUTTONS
	sf::Color buttonColour;
	sf::Color buttonHighlightedColour;
	sf::RectangleShape boxClickerButton;
	sf::RectangleShape backButton;

	//SPRITES
	sf::Sprite boxClickerSprite;
	sf::Texture boxClickerTexture;
	sf::IntRect deselectedRect;
	sf::IntRect selectedRect;

	//VECTORS
	std::vector<sf::Sprite> gameSprites;

	//BOOLS
	bool mouseHeld;
	bool menuOpen;
	bool boxClickerLaunched;
	bool spriteEnlarging;
	bool spriteShrinking;

	//PRIVATE FUNCTIONS
	void initVar(sf::VideoMode screen_bounds);
	void initBackground();
	void initFont(sf::Font font);
	void initText();
	void initButtons();
	void updateSpriteSize(sf::Sprite& sprite, sf::IntRect target_size);

public:

	//CONSTRUCTORS AND DESTRUCTORS
	GamesMenu(sf::Font font, sf::VideoMode screen_bounds);
	virtual ~GamesMenu();

	//PUBLIC FUNCTIONS
	void menuInteraction(sf::Vector2f mouse_pos);

	//ACCESSORS
	const bool getMenuOpen() const;
	const bool getBoxClickerLaunched() const;

	//MODIFIERS
	void setMenuOpen(bool is_open);
	void setBoxClickerLaunched(bool is_launched);

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

