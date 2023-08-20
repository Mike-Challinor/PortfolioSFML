#include "SwagBall.h"



void SwagBall::initVariables()
{

}

void SwagBall::initShape(sf::VideoMode screen_bounds)
{
	this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color color;

	switch (this->type)
	{

	case DEFAULT:

		color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
		break;

	case DAMAGING:

		color = sf::Color::Red;
		this->shape.setOutlineColor(sf::Color::White);
		this->shape.setOutlineThickness(2.f);
		break;

	case HEALING:

		color = sf::Color::Green;
		this->shape.setOutlineColor(sf::Color::White);
		this->shape.setOutlineThickness(2.f);
		break;

	}
	
	this->shape.setFillColor(color);

	int width_range = static_cast<int>(screen_bounds.width - this->shape.getGlobalBounds().width - 20);
	int height_range = static_cast<int>(screen_bounds.height - this->shape.getGlobalBounds().height - 20);

	this->shape.setPosition(
		sf::Vector2f(
			static_cast<float>(10 + rand() % width_range),
			static_cast<float>(10 + rand() % height_range)
		)
	);
}

SwagBall::SwagBall(sf::VideoMode screen_bounds, int type) : type(type)
{
	this->initShape(screen_bounds);
}

SwagBall::~SwagBall()
{

}

const sf::CircleShape SwagBall::getShape() const
{
	return this->shape;
}

const int& SwagBall::getType() const
{
	return this->type;
}

void SwagBall::update()
{

}

void SwagBall::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
