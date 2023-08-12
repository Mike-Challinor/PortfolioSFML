#include "GamesMenu.h"
#include <iostream>

//PRIVATE FUNCTIONS

void GamesMenu::initVar(sf::VideoMode screen_bounds)
{
	this->mouseHeld = false;
	this->screenBounds = screen_bounds;
	this->boxClickerLaunched = false;
}

void GamesMenu::initBackground()
{
	//Load the texture
	if (!this->backgroundTexture.loadFromFile("Resources/Textures/menuBackground.png"))
	{
		std::cout << "ERROR::GAMESMENU::INITBACKGROUND:: Unable to load backgroundTexture.png" << std::endl;
	}

	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.setScale(1, 1);
}

void GamesMenu::initFont(sf::Font font)
{
	this->font = font;
}

void GamesMenu::initText()
{
	//titleText Text Init
	this->menuTitleText.setFont(this->font);
	this->menuTitleText.setCharacterSize(64);
	this->menuTitleText.setFillColor(sf::Color::White);
	this->menuTitleText.setString("Games Menu");
	this->menuTitleText.setPosition(this->screenBounds.width / 2 - this->menuTitleText.getGlobalBounds().width / 2, 20.f);

	//backButton Text Init
	this->backButtonText.setFont(this->font);
	this->backButtonText.setCharacterSize(24);
	this->backButtonText.setFillColor(sf::Color::Black);
	this->backButtonText.setString("Back");
	this->backButtonText.setPosition(this->backButton.getGlobalBounds().left + this->backButton.getGlobalBounds().width / 2 - this->backButtonText.getGlobalBounds().width / 2, this->backButton.getGlobalBounds().top + this->backButton.getGlobalBounds().height / 2 - this->backButtonText.getGlobalBounds().height / 1.2);

	//BoxClicker title text
	this->boxClickerTitleText.setFont(this->font);
	this->boxClickerTitleText.setCharacterSize(32);
	this->boxClickerTitleText.setFillColor(sf::Color::White);
	this->boxClickerTitleText.setString("Box Clicker");
	this->boxClickerTitleText.setPosition(this->boxClickerButton.getGlobalBounds().left + this->boxClickerButton.getGlobalBounds().width / 2 - this->boxClickerTitleText.getGlobalBounds().width / 2, this->boxClickerButton.getGlobalBounds().top - this->boxClickerTitleText.getGlobalBounds().height * 1.5);
}

void GamesMenu::initButtons()
{
	//Set button colours
	this->buttonColour = sf::Color::White;
	this->buttonHighlightedColour = sf::Color::Yellow;

	//Init BoxClicker button background
	this->boxClickerButton.setFillColor(this->buttonColour);
	this->boxClickerButton.setSize(sf::Vector2f(200.f, 150.f));
	this->boxClickerButton.setPosition(this->screenBounds.width / 2 - this->boxClickerButton.getGlobalBounds().width - 50.f, this->screenBounds.height / 2 - this->boxClickerButton.getGlobalBounds().height + 10.f);

	//Init the BoxClicker button texture
	if (!this->boxClickerTexture.loadFromFile("Resources/Textures/boxClickerThumbnail.png"))
	{
		std::cout << "ERROR::GAMESMENU::INITBUTTONS:: Failed to load boxClickerThumbnail.png" << std::endl;
	}

	//Init Box Clicker button sprite
	this->boxClickerSprite.setTexture(this->boxClickerTexture);
	this->boxClickerSprite.setScale(0.238f, 0.232f);
	this->boxClickerSprite.setPosition(this->boxClickerButton.getGlobalBounds().left + 5, this->boxClickerButton.getGlobalBounds().top + 5);

	//Init Back button background
	this->backButton.setFillColor(this->buttonColour);
	this->backButton.setSize(sf::Vector2f(150.f, 50.f));
	this->backButton.setPosition(10.f, this->screenBounds.height - this->backButton.getGlobalBounds().height - 10.f);
}

//CONSTRUCTORS AND DESTRUCTORS

GamesMenu::GamesMenu(sf::Font font, sf::VideoMode screen_bounds)
{
	this->initVar(screen_bounds);
	this->initBackground();
	this->initFont(font);
	this->initButtons();
	this->initText();
}

GamesMenu::~GamesMenu()
{

}

//PUBLIC FUNCTIONS

void GamesMenu::menuInteraction(sf::Vector2f mouse_pos)
{
	//Check for button presses.
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{

			this->mouseHeld = true;

			if (this->boxClickerButton.getGlobalBounds().contains(mouse_pos))
			{
				this->menuOpen = false;
				this->boxClickerLaunched = true;

			}

			else if (this->backButton.getGlobalBounds().contains(mouse_pos))
			{
				this->menuOpen = false;
			}

		}

	}

	else
	{
		this->mouseHeld = false;
	}
}

//ACCESSORS

const bool GamesMenu::getMenuOpen() const
{
	return this->menuOpen;
}

const bool GamesMenu::getBoxClickerLaunched() const
{
	return this->boxClickerLaunched;
}

//MODIFIERS

void GamesMenu::setMenuOpen(bool is_open)
{
	this->menuOpen = is_open;
}

//UPDATES

void GamesMenu::update(sf::Vector2f mousePos)
{
	this->updateGUI(mousePos);
}

void GamesMenu::updateGUI(sf::Vector2f mousePos)
{
	if (this->boxClickerButton.getGlobalBounds().contains(mousePos) && this->boxClickerButton.getFillColor() == this->buttonColour)
	{
		this->boxClickerButton.setFillColor(this->buttonHighlightedColour);
	}

	else if (!this->boxClickerButton.getGlobalBounds().contains(mousePos) && this->boxClickerButton.getFillColor() == this->buttonHighlightedColour)
	{
		this->boxClickerButton.setFillColor(this->buttonColour);
	}

	if (this->backButton.getGlobalBounds().contains(mousePos) && this->backButton.getFillColor() == this->buttonColour)
	{
		this->backButton.setFillColor(this->buttonHighlightedColour);
	}

	else if (!this->backButton.getGlobalBounds().contains(mousePos) && this->backButton.getFillColor() == this->buttonHighlightedColour)
	{
		this->backButton.setFillColor(this->buttonColour);
	}
}

//RENDERS

void GamesMenu::setBoxClickerLaunched(bool is_launched)
{
	this->boxClickerLaunched = is_launched;
}

void GamesMenu::render(sf::RenderTarget& target)
{
	this->renderGUI(target);
}

void GamesMenu::renderGUI(sf::RenderTarget& target)
{
	this->renderBackground(target);
	this->renderButtons(target);
	this->renderText(target);
}

void GamesMenu::renderBackground(sf::RenderTarget& target)
{
	target.draw(this->backgroundSprite);
}

void GamesMenu::renderText(sf::RenderTarget& target)
{
	target.draw(this->menuTitleText);
	target.draw(this->boxClickerTitleText);
	target.draw(this->backButtonText);
}

void GamesMenu::renderButtons(sf::RenderTarget& target)
{
	target.draw(this->boxClickerButton);
	target.draw(this->boxClickerSprite);
	target.draw(this->backButton);
}
