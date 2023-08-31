#include "Counter.h"

//PRIVATE FUNCTIONS

void Counter::initVar(int player_num)
{
	this->playerNum = player_num;
	this->movementSpeed = 10.0f;
	this->isReleased = false;
}

void Counter::initTexture(sf::Texture texture)
{
	this->texture = texture;
}

void Counter::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.133, 0.133);
	this->sprite.setPosition(0, 40);

	switch (this->playerNum)
	{
	case 0:
		std::cout << "No player assigned" << std::endl;
		break;

	case 1:
		this->sprite.setColor(sf::Color::Red);
		break;

	case 2:
		this->sprite.setColor(sf::Color::Yellow);
		break;
	}
}

void Counter::moveSprite()
{
	//Check if the sprite has reached its destination y position
	if (this->sprite.getPosition().y <= this->moveYPos)
	{
		//Move the sprite down
		this->sprite.move(0, this->movementSpeed);
	}
	
	else
	{
		//Stop the counter moving
		this->isMoving = false;
	}
}

//CONSTRUCTORS AND DESTRUCTORS

Counter::Counter()
{
}

Counter::~Counter()
{
}

//PUBLIC FUNCTIONS

void Counter::initCounter(int player_num, sf::Texture texture)
{
	this->initVar(player_num);
	this->initTexture(texture);
	this->initSprite();
}

//ACCESSORS

const sf::FloatRect Counter::getBounds()
{
	return this->sprite.getGlobalBounds();
}

const bool Counter::getIsMoving() const
{
	return this->isMoving;
}

const bool Counter::getIsReleased() const
{
	return this->isReleased;
}

//MODIFIERS

void Counter::setPosition(float pos_x)
{
	this->sprite.setPosition(pos_x, this->sprite.getGlobalBounds().top);
}

void Counter::setMoving(float y_pos)
{
	this->moveYPos = y_pos;
	this->isMoving = true;
}

void Counter::setIsReleased(bool is_released)
{
	this->isReleased = is_released;
}

//UPDATES

void Counter::update()
{
	if (this->isMoving)
	{
		this->moveSprite();
	}
}

//RENDERS

void Counter::render(sf::RenderTarget& target) const
{
	target.draw(this->sprite);
}
