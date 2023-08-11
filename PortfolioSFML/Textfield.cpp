#include "Textfield.h"
#include <iostream>

void Textfield::initVar(sf::VideoMode screen_bounds)
{
	this->screenBounds = screen_bounds;
	this->inFocus = false;
	this->defaultText = "Enter name: ";
}

void Textfield::initShapes()
{
	//Init button colour
	this->buttonColour = sf::Color::White;
	this->buttonHighlightedColour = sf::Color::Yellow;

	//Init textbox
	this->textBox.setFillColor(sf::Color(20, 20, 177));
	this->textBox.setOutlineColor(sf::Color::Black);
	this->textBox.setOutlineThickness(1.f);
	this->textBox.setSize(sf::Vector2f(200.f, 30.f));
	this->textBox.setPosition(this->screenBounds.width / 2 - this->textBox.getGlobalBounds().width / 2, this->screenBounds.height - this->screenBounds.height / 2.5);

	//Init textbox border
	this->textBoxBorder.setFillColor(sf::Color(this->buttonColour));
	this->textBoxBorder.setSize(sf::Vector2f(210.f, 40.f));
	this->textBoxBorder.setPosition(this->textBox.getGlobalBounds().left - 4.f, this->textBox.getGlobalBounds().top - 4.f);
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
	this->userInputText.setString(this->defaultText);
	this->userInputText.setPosition(this->textBox.getGlobalBounds().left + 5.f, this->textBox.getGlobalBounds().top + this->userInputText.getGlobalBounds().height / 3);

}

void Textfield::initCursor()
{
	//Init cursor
	this->cursor.setFillColor(sf::Color(177, 177, 177));
	this->cursor.setOutlineColor(sf::Color::Black);
	this->cursor.setOutlineThickness(0.5f);
	this->cursor.setSize(sf::Vector2f(1.f, this->userInputText.getGlobalBounds().height));
	this->cursor.setPosition(this->userInputText.getGlobalBounds().left + this->userInputText.getGlobalBounds().width + this->userInputText.getLetterSpacing() * 2, this->userInputText.getGlobalBounds().top);
	
}

Textfield::Textfield(sf::VideoMode screen_bounds)
{
	this->initVar(screen_bounds);
	this->initShapes();
	this->initFont();
	this->initText();
	this->initCursor();
}

const bool Textfield::getInFocus() const
{
	return this->inFocus;
}

const sf::Vector2f Textfield::getSize() const
{
	return this->textBox.getSize();
}

const sf::RectangleShape Textfield::getShape() const
{
	return this->textBox;
}

const std::string Textfield::getString() const
{
	return this->userInput;
}

void Textfield::setInFocus(bool in_focus)
{
	this->inFocus = in_focus;

	if (this->userInput.empty())
	{
		if (this->inFocus)
		{
			this->userInputText.setString("");
		}
		
		else
		{
			this->userInputText.setString(defaultText);
		}
	}
}

void Textfield::setPosition(float x, float y)
{

	this->textBox.setPosition(x, y);
}

void Textfield::addChar(char characterToAdd)
{
	if (getInFocus())
	{
		this->userInput += characterToAdd;
		this->userInputText.setString(userInput);

		if (this->userInputText.getGlobalBounds().width >= this->textBox.getGlobalBounds().width - 10.f)
		{
			this->removeChar();
		}
	}
	
}

void Textfield::removeChar()
{
	
	if (!this->userInput.empty())
	{
		this->userInput.pop_back();
	}
}

void Textfield::update(sf::Vector2f mouse_pos)
{
	this->updateButtons(mouse_pos);
	this->updateText();
	this->updateCursor();
}

void Textfield::updateText()
{
	if (this->inFocus)
	{
		this->userInputText.setString(userInput);
	}
	
}

void Textfield::updateButtons(sf::Vector2f mouse_pos)
{
	if (this->textBox.getGlobalBounds().contains(mouse_pos))
	{
		this->textBoxBorder.setFillColor(this->buttonHighlightedColour);
	}

	else
	{
		this->textBoxBorder.setFillColor(this->buttonColour);
	}
}

void Textfield::updateCursor()
{
	this->cursor.setPosition(this->userInputText.getGlobalBounds().left + this->userInputText.getGlobalBounds().width + this->userInputText.getLetterSpacing() * 2, this->userInputText.getGlobalBounds().top);
}

void Textfield::render(sf::RenderTarget& target)
{
	this->renderShapes(target);
	this->renderText(target);
	
}

void Textfield::renderShapes(sf::RenderTarget& target)
{
	target.draw(this->textBoxBorder);
	target.draw(this->textBox);
	target.draw(this->cursor);
}

void Textfield::renderText(sf::RenderTarget& target)
{
	target.draw(this->userInputText);
}
