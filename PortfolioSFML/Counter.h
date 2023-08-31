#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <SFML/Window.hpp> 

class Counter
{
private:

	sf::Texture texture;
	sf::Sprite sprite;

	//INTS
	int playerNum;

	//FLOATS
	float movementSpeed;
	float moveYPos;

	//BOOLS
	bool isMoving;
	bool isReleased;

	//PRIVATE FUNCTIONS
	void initVar(int player_num);
	void initTexture(sf::Texture texture);
	void initSprite();

	void moveSprite();


public:

	//CONSTRUCTORS AND DESTRUCTORS
	Counter();
	~Counter();

	//PUBLIC FUNCTIONS
	void initCounter(int player_num, sf::Texture texture);

	//ACCESSORS
	const sf::FloatRect getBounds();
	const bool getIsMoving() const;
	const bool getIsReleased() const;

	//MODIFIERS
	void setPosition(float pos_x);
	void setMoving(float y_pos);
	void setIsReleased(bool is_released);

	//UPDATES
	void update();

	//RENDERS
	void render(sf::RenderTarget& target) const;
};

