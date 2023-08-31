#include "BoardTile.h"

//PRIVATE FUNCTIONS

void BoardTile::initVar()
{
	this->isEmpty = true;
	this->playerNum = 0;
}

void BoardTile::initSprite(float pos_x, float pos_y)
{
	//Init texture
	if (!this->texture.loadFromFile("Resources/Textures/boardTile.png"))
	{
		std::cout << "ERROR::BOARDTILE::INITSPRITE:: Failed to load boardTile.png";
	}

	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.133, 0.133);
	this->sprite.setPosition(pos_x, pos_y);
}

//CONSTRUCTORS AND DESTRUCTORS

BoardTile::BoardTile()
{

}

BoardTile::~BoardTile()
{

}

//PUBLIC FUNCTIONS

void BoardTile::initTile(float pos_x, float pos_y)
{
	this->initVar();
	this->initSprite(pos_x, pos_y);
}

//ACCESSORS

const bool BoardTile::getIsEmpty()
{
	return this->isEmpty;
}

const sf::FloatRect BoardTile::getBounds()
{
	return this->sprite.getGlobalBounds();
}

//MODIFIERS

void BoardTile::setPlayerNum(int player_num)
{
	this->playerNum = player_num;
}

void BoardTile::setIsEmpty(bool is_empty)
{
	this->isEmpty = is_empty;
}

//RENDERS

void BoardTile::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
