#include "Textfield.h"
#include <iostream>

void Textfield::initVar(sf::VideoMode screen_bounds)
{
	this->screenBounds = screen_bounds;
}

void Textfield::initShapes()
{
	//Init textbox
	this->textBox.setFillColor(sf::Color(20, 20, 177));
	this->textBox.setOutlineColor(sf::Color::Black);
	this->textBox.setOutlineThickness(1.f);
	this->textBox.setSize(sf::Vector2f(200.f, 30.f));
	this->textBox.setPosition(this->screenBounds.width / 2 - this->textBox.getGlobalBounds().width / 2, this->screenBounds.height - this->screenBounds.height / 2.5);
}

void Textfield::initFont()
{
	if (!this->font.loadFromFile("Fonts/Arial.ttf"))
	{
		std::cout << "ERROR::TEXTFIELD::INITFONT:: Failed to load arial.ttf" << std::endl;
	}
}

void Textfield::initText()
{
	//Init user text
	this->userInputText.setFont(this->font);
	this->userInputText.setCharacterSize(18);
	this->userInputText.setFillColor(sf::Color::White);
	this->userInputText.setString("Enter name:");
	this->userInputText.setPosition(this->textBox.getGlobalBounds().left + 5.f, this->textBox.getGlobalBounds().top + this->userInputText.getGlobalBounds().height / 2);

}

void Textfield::initCursor()
{
	//Init cursor
	this->cursor.setFillColor(sf::Color(177, 177, 177));
	this->cursor.setOutlineColor(sf::Color::Black);
	this->cursor.setOutlineThickness(0.5f);
	this->cursor.setSize(sf::Vector2f(1.f, this->userInputText.getGlobalBounds().height));
	this->cursor.setPosition(this->userInputText.getGlobalBounds().left + this->userInputText.getGlobalBounds().width + this->userInputText.getLetterSpacing(), this->userInputText.getGlobalBounds().top);
	
}

Textfield::Textfield(sf::VideoMode screen_bounds)
{
	this->initVar(screen_bounds);
	this->initShapes();
	this->initFont();
	this->initText();
	this->initCursor();
}

const bool Textfield::getInFocus()
{
	return this->inFocus;
}

const sf::Vector2f Textfield::getSize()
{
	return this->textBox.getSize();
}

void Textfield::setInFocus(bool in_focus)
{
	this->inFocus = in_focus;
}

void Textfield::setPosition(float x, float y)
{

	this->textBox.setPosition(x, y);
}

void Textfield::setString(char characterToAdd)
{
	this->userInput += characterToAdd;
	this->userInputText.setString(userInput);
}

void Textfield::update()
{
}

void Textfield::render(sf::RenderTarget& target)
{
	this->renderShapes(target);
	this->renderText(target);
	
}

void Textfield::renderShapes(sf::RenderTarget& target)
{
	target.draw(this->textBox);
	target.draw(this->cursor);
}

void Textfield::renderText(sf::RenderTarget& target)
{
	target.draw(this->userInputText);
}
