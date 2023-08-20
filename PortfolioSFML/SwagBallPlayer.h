#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <SFML/Window.hpp> 


class SwagBallPlayer
{
private:
	//Variables

	//Shapes
	sf::RectangleShape shape;

	//Ints
	int hp;
	int hpMax;

	//Floats
	float movementSpeed;

	//Init functions
	void initVariables();
	void initShape();

	bool checkLeftColl();
	bool checkRightColl(sf::VideoMode screen_bounds);
	bool checkTopColl();
	bool checkBottomColl(sf::VideoMode screen_bounds);

public:
	//Constructors and Destructors
	SwagBallPlayer(float x = 0.f, float y = 0.f);
	virtual ~SwagBallPlayer();

	//Accessors
	const sf::RectangleShape& getShape() const;
	const int& getHp() const;
	const int& getHpMax() const;

	//Functions
	void takeDamage(const int damage);
	void gainHealth(const int health);

	void updateInput();
	void updateWindowsBoundCollision(sf::VideoMode screen_bounds);
	void update(sf::VideoMode screen_bounds);
	void render(sf::RenderTarget& target);
};

