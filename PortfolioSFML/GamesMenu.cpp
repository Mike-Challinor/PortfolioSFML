#include "GamesMenu.h"

//PRIVATE FUNCTIONS

void GamesMenu::initVar(sf::VideoMode screen_bounds)
{
	this->mouseHeld = false;
	this->screenBounds = screen_bounds;
	this->boxClickerLaunched = false;
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
}

void GamesMenu::initButtons()
{
	
}

//CONSTRUCTORS AND DESTRUCTORS

GamesMenu::GamesMenu(sf::Font font, sf::VideoMode screen_bounds)
{
	void initVar(sf::VideoMode screen_bounds);
	void initFont(sf::Font font);
	void initButtons();
	void initText();
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

//MODIFIERS

void GamesMenu::setMenuOpen(bool is_open)
{
	this->menuOpen = is_open;
}

//UPDATES

void GamesMenu::update()
{
}

//RENDERS

void GamesMenu::render(sf::RenderTarget& target)
{
	target.clear();

	this->renderText(target);
}

void GamesMenu::renderText(sf::RenderTarget& target)
{
	target.draw(menuTitleText);
}
