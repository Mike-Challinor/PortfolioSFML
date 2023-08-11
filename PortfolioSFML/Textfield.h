#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Textfield
{
private:
	sf::VideoMode screenBounds;

	//COLOURS
	sf::Color buttonColour;
	sf::Color buttonHighlightedColour;

	sf::RectangleShape textBoxBorder;
	sf::RectangleShape textBox;
	sf::RectangleShape cursor;

	sf::Font font;
	sf::Text userInputText;

	std::string userInput;
	std::string defaultText;

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
	const bool getInFocus() const;
	const sf::Vector2f getSize() const;
	const sf::RectangleShape getShape() const;

	//MODIFIERS
	void setInFocus(bool in_focus);
	void setPosition(float x, float y);
	void addChar(char characterToAdd);
	void removeChar();

	//UPDATES
	void update(sf::Vector2f mouse_pos);
	void updateText();
	void updateButtons(sf::Vector2f mouse_pos);
	void updateCursor();
	
	//RENDERS
	void render(sf::RenderTarget& target);
	void renderShapes(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
};

