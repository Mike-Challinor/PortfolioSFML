#pragma once

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class BaseGameThumbnails
{
protected:
	sf::Sprite* sprite = nullptr;
	sf::Texture* spriteTexture = nullptr;
	sf::Clock enlargingTimer;
	sf::Clock shrinkingTimer;
	sf::IntRect selectedRect = sf::IntRect(0, 0, 800, 600);
	sf::IntRect deselectedRect = sf::IntRect(200, 0, 600, 600);
	sf::Color buttonColour;
	sf::RectangleShape highlightBox;

	//BOOLS
	bool isEnlarging;
	bool isShrinking;


public:

	BaseGameThumbnails();
	virtual ~BaseGameThumbnails();

	//PUBLIC FUNCTIONS

	void initTexture(std::string file_path);
	void initSprite();
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

	//UPDATES
	void update();

	//RENDERS
	void render(sf::RenderTarget& target);

};