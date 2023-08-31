#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <SFML/Window.hpp> 

class BoardTile
{
private:

	sf::Sprite sprite;
	sf::Texture texture;

	bool isEmpty;

	int playerNum;

	void initVar();
	void initSprite(float pos_x, float pos_y);

public:

	//CONSTRUCTORS AND DESTRUCTORS
	BoardTile();
	~BoardTile();

	//PUBLIC FUNCTIONS
	void initTile(float pos_x, float pos_y);

	//ACCESSORS
	const bool getIsEmpty();
	const sf::FloatRect getBounds();

	//MODIFIERS
	void setPlayerNum(int player_num);
	void setIsEmpty(bool is_empty);

	//RENDERS
	void render(sf::RenderTarget& target);


};

