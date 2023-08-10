#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Textfield
{
private:
	sf::VideoMode screenBounds;

	sf::RectangleShape textBox;
	sf::RectangleShape cursor;

	sf::Font font;
	sf::Text userInputText;

	std::string userInput;

	bool inFocus;

	//PRIVATE FUNCTIONS
	void initVar(sf::VideoMode screen_bounds);
	void initShapes();
	void initFont();
	void initText();
	void initCursor();

public: 

	//CONSTRUCTORS AND DESTRUCTORS
	Textfield(sf::VideoMode screen_bounds);

	//PUBLIC FUNCTIONS

	//ACCESSORS
	const bool getInFocus();
	const sf::Vector2f getSize();

	//MODIFIERS
	void setInFocus(bool in_focus);
	void setPosition(float x, float y);
	void setString(char characterToAdd);

	//UPDATES
	void update();
	
	//RENDERS
	void render(sf::RenderTarget& target);
	void renderShapes(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
};

