#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <SFML/Window.hpp> 

enum swagBallTypes {DEFAULT = 0, DAMAGING, HEALING, NROFTYPES};

class SwagBall
{
private:
	
	//Variables

	//Shapes
	sf::CircleShape shape;

	//Types
	int type;

	//Init Functions
	void initVariables();
	void initShape(sf::VideoMode screen_bounds);

	

public:
	//Constructors and Destructors
	SwagBall(sf::VideoMode screen_bounds, int type);
	virtual ~SwagBall();

	//Accessors
	const sf::CircleShape getShape() const;	
	const int& getType() const;
	
	//Functions
	void update();
	void render(sf::RenderTarget& target);
};

