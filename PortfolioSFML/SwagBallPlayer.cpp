#include "SwagBallPlayer.h"

//Init Functions
void SwagBallPlayer::initVariables()
{
	this->movementSpeed = 5.f;
	this->hpMax = 5;
	this->hp = this->hpMax;
}

void SwagBallPlayer::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}


//Collision Checks
bool SwagBallPlayer::checkLeftColl()
{
	if (this->shape.getGlobalBounds().left <= 0.f)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool SwagBallPlayer::checkRightColl(sf::VideoMode screen_bounds)
{
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= screen_bounds.width)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool SwagBallPlayer::checkTopColl()
{
	if (this->shape.getGlobalBounds().top <= 0.f)
	{
		return true;
	}

	else
	{
		return false;
	}
	
}

bool SwagBallPlayer::checkBottomColl(sf::VideoMode screen_bounds)
{
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= screen_bounds.height)
	{
		return true;
	}

	else
	{
		return false;
	}
	
}


//Constructos and Destructors
SwagBallPlayer::SwagBallPlayer(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initVariables();
	this->initShape();
}

SwagBallPlayer::~SwagBallPlayer()
{

}


//Accessors
const sf::RectangleShape& SwagBallPlayer::getShape() const
{
	return this->shape;
}

const int& SwagBallPlayer::getHp() const
{
	return this->hp;
}

const int& SwagBallPlayer::getHpMax() const
{
	return this->hpMax;
}


//Functions
void SwagBallPlayer::takeDamage(const int damage)
{
	if (this->hp > 0)
	{
		this->hp -= damage;
	}

	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void SwagBallPlayer::gainHealth(const int health)
{
	if (this->hp < this->hpMax)
	{
		this->hp += health;
	}

	if (this->hp > this->hpMax)
	{
		this->hp = this->hpMax;
	}
}

void SwagBallPlayer::updateInput()
{
	//Keyboard input

	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}

	//Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}

	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0.f, -this->movementSpeed);
	}

	//Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->shape.move(0.f, this->movementSpeed);
	}
}

void SwagBallPlayer::updateWindowsBoundCollision(sf::VideoMode screen_bounds)
{
	//Left

	if (this->checkLeftColl())
	{
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);		
	}

	//Right
	else if (this->checkRightColl(screen_bounds))
	{
		this->shape.setPosition(screen_bounds.width - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	}

	//Top
	if (this->checkTopColl())
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	}

	//Bottom

	else if (this->checkBottomColl(screen_bounds))
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left, screen_bounds.height - this->shape.getGlobalBounds().height);
	}

}

void SwagBallPlayer::update(sf::VideoMode screen_bounds)
{
	//Update keyboard/movement input
	this->updateInput();

	//Window bounds collision
	this->updateWindowsBoundCollision(screen_bounds);
}

void SwagBallPlayer::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
