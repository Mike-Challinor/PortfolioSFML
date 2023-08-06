#include "PauseMenu.h"

#include <iostream>

//PRIVATE FUNCTIONS

void PauseMenu::initVar(sf::VideoMode screen_bounds)
{
	this->hasQuit = false;
	this->gamePaused = false;
	this->mouseHeld = false;
	this->screenBounds = screen_bounds;
}

void PauseMenu::initBackground()
{
	//Load the texture
	if (!this->backgroundTexture.loadFromFile("Textures/pauseMenuBackground.png"))
	{
		std::cout << "ERROR::PAUSEMENU::INITBACKGROUND:: Unable to load backgroundTexture.png" << std::endl;
	}

	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.setScale(1, 1);
	this->backgroundSprite.setPosition(this->screenBounds.width / 2 - this->backgroundSprite.getGlobalBounds().width / 2, 50.f);
}

void PauseMenu::initFont(sf::Font font)
{
	this->font = font;
}

void PauseMenu::initText()
{
	//titleText Text Init
	this->menuTitleText.setFont(this->font);
	this->menuTitleText.setCharacterSize(64);
	this->menuTitleText.setFillColor(sf::Color::White);
	this->menuTitleText.setString("Pause Menu");
	this->menuTitleText.setPosition(this->screenBounds.width / 2 - this->menuTitleText.getGlobalBounds().width / 2, 20.f);

	//Resume Text Init
	this->resumeButtonText.setFont(this->font);
	this->resumeButtonText.setCharacterSize(32);
	this->resumeButtonText.setFillColor(sf::Color::Black);
	this->resumeButtonText.setString("Resume");
	this->resumeButtonText.setPosition(this->resumeButton.getPosition().x + (this->resumeButton.getGlobalBounds().width / 2) - (resumeButtonText.getGlobalBounds().width / 2), this->resumeButton.getPosition().y + (this->resumeButton.getGlobalBounds().height / 2) - (resumeButtonText.getGlobalBounds().height / 1.2));

	//Quit Text Init
	this->quitButtonText.setFont(this->font);
	this->quitButtonText.setCharacterSize(32);
	this->quitButtonText.setFillColor(sf::Color::Black);
	this->quitButtonText.setString("Quit");
	this->quitButtonText.setPosition(this->quitButton.getPosition().x + (this->quitButton.getGlobalBounds().width / 2) - (quitButtonText.getGlobalBounds().width / 2), this->quitButton.getPosition().y + (this->quitButton.getGlobalBounds().height / 2) - (quitButtonText.getGlobalBounds().height / 1.2));

	//Options Text Init
	this->optionsButtonText.setFont(this->font);
	this->optionsButtonText.setCharacterSize(32);
	this->optionsButtonText.setFillColor(sf::Color::Black);
	this->optionsButtonText.setString("Options");
	this->optionsButtonText.setPosition(this->quitButton.getPosition().x + (this->optionsButton.getGlobalBounds().width / 2) - (optionsButtonText.getGlobalBounds().width / 2), this->optionsButton.getPosition().y + (this->optionsButton.getGlobalBounds().height / 2) - (optionsButtonText.getGlobalBounds().height / 1.2));
}

void PauseMenu::initButtons()
{
	//Set button colours
	this->buttonColour = sf::Color::White;
	this->buttonHighlightedColour = sf::Color::Yellow;

	//Init Resume button
	this->resumeButton.setFillColor(this->buttonColour);
	this->resumeButton.setSize(sf::Vector2f(200.f, 50.f));
	this->resumeButton.setPosition(this->screenBounds.width / 2 - this->resumeButton.getGlobalBounds().width / 2, this->screenBounds.height / 2 - this->resumeButton.getGlobalBounds().height * 2);

	//Init Quit button
	this->quitButton.setFillColor(this->buttonColour);
	this->quitButton.setSize(sf::Vector2f(200.f, 50.f));
	this->quitButton.setPosition(this->screenBounds.width / 2 - this->quitButton.getGlobalBounds().width / 2, this->screenBounds.height / 2 + this->quitButton.getGlobalBounds().height * 2);

	//Init Quit button
	this->optionsButton.setFillColor(this->buttonColour);
	this->optionsButton.setSize(sf::Vector2f(200.f, 50.f));
	this->optionsButton.setPosition(this->screenBounds.width / 2 - this->quitButton.getGlobalBounds().width / 2, this->screenBounds.height / 2);
}

//CONSTRUCTORS AND DESTRUCTORS

PauseMenu::PauseMenu(sf::Font font, sf::VideoMode screen_bounds)
{
	this->initVar(screen_bounds);
	this->initBackground();
	this->initFont(font);
	this->initButtons();
	this->initText();
}

PauseMenu::~PauseMenu()
{

}

//PUBLIC FUNCTIONS


void PauseMenu::menuInteraction(sf::Vector2f mouse_pos)
{
	//Check for button presses.
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{

			this->mouseHeld = true;

			if (this->resumeButton.getGlobalBounds().contains(mouse_pos))
			{
				std::cout << "Game unpaused" << std::endl;
				this->gamePaused = false;
			}

			else if (this->quitButton.getGlobalBounds().contains(mouse_pos))
			{
				this->hasQuit = true;
				this->gamePaused = false;
			}

		}

	}

	else
	{
		this->mouseHeld = false;
	}
}

//ACCESSORS

const bool PauseMenu::getPaused() const
{
	return this->gamePaused;
}

const bool PauseMenu::getHasQuit() const
{
	return this->hasQuit;
}

//MODIFIERS

void PauseMenu::setPaused(bool is_paused)
{
	this->gamePaused = is_paused;
}

void PauseMenu::setHasQuit(bool has_quit)
{
	this->hasQuit = has_quit;
}

//UPDATES

void PauseMenu::update(sf::Vector2f mousePos)
{
	this->updateGUI(mousePos);
}

//RENDERS

void PauseMenu::updateGUI(sf::Vector2f mousePos)
{
	if (this->resumeButton.getGlobalBounds().contains(mousePos) && this->resumeButton.getFillColor() == this->buttonColour)
	{
		this->resumeButton.setFillColor(this->buttonHighlightedColour);
	}

	else if (!this->resumeButton.getGlobalBounds().contains(mousePos) && this->resumeButton.getFillColor() == this->buttonHighlightedColour)
	{
		this->resumeButton.setFillColor(this->buttonColour);
	}

	if (this->quitButton.getGlobalBounds().contains(mousePos) && this->quitButton.getFillColor() == this->buttonColour)
	{
		this->quitButton.setFillColor(this->buttonHighlightedColour);
	}

	else if (!this->quitButton.getGlobalBounds().contains(mousePos) && this->quitButton.getFillColor() == this->buttonHighlightedColour)
	{
		this->quitButton.setFillColor(this->buttonColour);
	}
}

void PauseMenu::render(sf::RenderTarget& target)
{
	this->renderGUI(target);
}

void PauseMenu::renderGUI(sf::RenderTarget& target)
{
	this->renderBackground(target);
	this->renderButtons(target);
	this->renderText(target);
}

void PauseMenu::renderBackground(sf::RenderTarget& target)
{
	target.draw(this->backgroundSprite);
}

void PauseMenu::renderButtons(sf::RenderTarget& target)
{
	target.draw(this->resumeButton);
	target.draw(this->quitButton);
	target.draw(this->optionsButton);
}

void PauseMenu::renderText(sf::RenderTarget& target)
{
	target.draw(this->menuTitleText);
	target.draw(this->resumeButtonText);
	target.draw(this->quitButtonText);
	target.draw(this->optionsButtonText);
}
