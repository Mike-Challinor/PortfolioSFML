#pragma once

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class BaseGameThumbnails
{
protected:

	//SPRITES
	sf::Sprite* sprite = nullptr;

	//TEXTURES
	sf::Texture* spriteTexture = nullptr;

	//FONTS
	sf::Font font;

	//TEXT
	sf::Text titleText;
	sf::Text descriptionText;

	//TIMERS
	sf::Clock enlargingTimer;
	sf::Clock shrinkingTimer;
	sf::Clock descriptionBoxFadeTimer;
	sf::Clock descriptionTextFadeTimer;

	//INT RECTS
	sf::IntRect selectedRect = sf::IntRect(0, 0, 800, 600);
	sf::IntRect deselectedRect = sf::IntRect(200, 0, 600, 600);

	//INTS
	int opacityIncrease;

	//FLOATS
	float fadeInSpeed;
	float fadeOutSpeed;

	//COLOURS
	sf::Color buttonColour;
	sf::Color descriptionBoxColour;
	sf::Color descriptionBoxHighlightColour;
	sf::Color descriptionTextColour;
	sf::Color descriptionHighlightedTextColour;
	sf::Color outlineTextColour;
	sf::Color outlineTextColourHighlighted;

	//SHAPES
	sf::RectangleShape highlightBox;
	sf::RectangleShape descriptionBox;

	//BOOLS
	bool isEnlarging;
	bool isShrinking;
	bool isHighlighted;
	bool isTextFading;


public:

	BaseGameThumbnails();
	virtual ~BaseGameThumbnails();

	//PUBLIC FUNCTIONS

	void initTexture(std::string file_path);
	void initSprite();
	void initText(sf::Font font, std::string title_string, std::string description_text);
	void updateSpriteSize();
	
	//ACCESSORS
	const sf::Sprite getSprite() const;
	const bool getIsEnlarging() const;
	const bool getIsShrinking() const;
	const sf::Color getHighlightColour() const;
	const sf::RectangleShape getHighlightBox() const;

	//MODIFIERS
	void setPosition(float pos_x, float pos_y);
	void setIsEnlarging(bool is_enlarging);
	void setIsShrinking(bool is_shrinking);
	void setHighlightColour(sf::Color color);
	void setTextColour(sf::Color color);
	void setisHighlighted(bool is_highlighted);

	//UPDATES
	void update();
	void updateGUI();
	void updateText();
	void updateShapes();

	//RENDERS
	void render(sf::RenderTarget& target);

};