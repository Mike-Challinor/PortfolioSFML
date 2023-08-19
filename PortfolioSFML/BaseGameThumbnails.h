#pragma once

#include <iostream>

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

	//BOOLS
	bool isEnlarging;
	bool isShrinking;

	virtual void initTexture();
	void initSprite();


public:

	BaseGameThumbnails();
	virtual ~BaseGameThumbnails();

	//PUBLIC FUNCTIONS
	void updateSpriteSize();
	
	//ACCESSORS
	const sf::Sprite getSprite() const;

	//MODIFIERS
	void setPosition(float pos_x, float pos_y);
	void setIsEnlarging(bool is_enlarging);
	void setIsShrinking(bool is_shrinking);

	//UPDATES
	void update();

	//RENDERS
	void render(sf::RenderTarget& target);

};