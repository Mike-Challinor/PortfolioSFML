#include "GamesMenu.h"
#include <iostream>

//PRIVATE FUNCTIONS

void GamesMenu::initVar(sf::VideoMode screen_bounds)
{
	this->mouseHeld = false;
	this->screenBounds = screen_bounds;
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
	this->boxClickerTitleText.setPosition(this->boxClickerThumbnail->getHighlightBox().getGlobalBounds().left + this->boxClickerThumbnail->getHighlightBox().getGlobalBounds().width / 2 - this->boxClickerTitleText.getGlobalBounds().width / 2, this->boxClickerThumbnail->getHighlightBox().getGlobalBounds().top - this->boxClickerTitleText.getGlobalBounds().height * 1.5);
}

void GamesMenu::initButtons()
{
	//Set button colours
	this->buttonColour = sf::Color(177, 177, 177, 177);
	this->buttonHighlightedColour = sf::Color::White;

	this->boxClickerThumbnail = new BaseGameThumbnails();
	this->ballSwagThumbnail = new BaseGameThumbnails();
	this->connect4Thumbnail = new BaseGameThumbnails();

	//Init Box Clicker button sprite
	this->boxClickerThumbnail->initTexture("Resources/Textures/boxClickerThumbnail.png");
	this->boxClickerThumbnail->initSprite();
	this->boxClickerThumbnail->setPosition(10.f, this->screenBounds.height / 2 - this->boxClickerThumbnail->getSprite().getGlobalBounds().height / 2);
	this->thumbnails.push_back(this->boxClickerThumbnail);
	
	//Init BallSwag button sprite
	this->ballSwagThumbnail->initTexture("Resources/Textures/ballSwagThumbnail.png");
	this->ballSwagThumbnail->initSprite();
	this->ballSwagThumbnail->setPosition(this->boxClickerThumbnail->getHighlightBox().getGlobalBounds().left + this->boxClickerThumbnail->getHighlightBox().getGlobalBounds().width + 10.f, this->screenBounds.height / 2 - this->ballSwagThumbnail->getSprite().getGlobalBounds().height / 2);
	this->thumbnails.push_back(this->ballSwagThumbnail);

	//Init Connect4 button sprite
	this->connect4Thumbnail->initTexture("Resources/Textures/connect4Thumbnail.png");
	this->connect4Thumbnail->initSprite();
	this->connect4Thumbnail->setPosition(this->ballSwagThumbnail->getHighlightBox().getGlobalBounds().left + this->ballSwagThumbnail->getHighlightBox().getGlobalBounds().width + 10.f, this->screenBounds.height / 2 - this->connect4Thumbnail->getSprite().getGlobalBounds().height / 2);
	this->thumbnails.push_back(this->connect4Thumbnail);

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
		if (this->mouseHeld == false && this->menuOpenedTimer.getElapsedTime().asSeconds() >= 0.3f)
		{
			this->mouseHeld = true;


			if (this->boxClickerThumbnail->getHighlightBox().getGlobalBounds().contains(mouse_pos))
			{
				this->menuOpen = false;
				this->gameLaunched = 1;
			}

			else if (this->ballSwagThumbnail->getHighlightBox().getGlobalBounds().contains(mouse_pos))
			{
				this->menuOpen = false;
				this->gameLaunched = 2;
			}

			else if (this->connect4Thumbnail->getHighlightBox().getGlobalBounds().contains(mouse_pos))
			{
				this->menuOpen = false;
				this->gameLaunched = 3;
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

const int GamesMenu::getGameLaunched() const
{
	return this->gameLaunched;
}

//MODIFIERS

void GamesMenu::setMenuOpen(bool is_open)
{
	this->menuOpen = is_open;
	this->menuOpenedTimer.restart();
}

void GamesMenu::setGameLaunched(int game_launched)
{
	this->gameLaunched = game_launched;
}

//UPDATES

void GamesMenu::update(sf::Vector2f mousePos)
{
	this->updateGUI(mousePos);

	for (BaseGameThumbnails* thumbnail : this->thumbnails)
	{
		thumbnail->update();
	}

	for (size_t i = 1; i < this->thumbnails.size(); i++)
	{
		this->thumbnails[i]->setPosition(this->thumbnails[i - 1]->getHighlightBox().getGlobalBounds().left + this->thumbnails[i - 1]->getHighlightBox().getGlobalBounds().width + 10.f, this->thumbnails[i]->getSprite().getGlobalBounds().top);
	}
}

void GamesMenu::updateGUI(sf::Vector2f mousePos)
{
	for (BaseGameThumbnails* thumbnail : this->thumbnails)
	{
		if (thumbnail->getSprite().getGlobalBounds().contains(mousePos) && thumbnail->getHighlightColour() == this->buttonColour)
		{
			thumbnail->setHighlightColour(this->buttonHighlightedColour);

			if (!thumbnail->getIsEnlarging())
			{
				thumbnail->setIsShrinking(false);
				thumbnail->setIsEnlarging(true);
			}

		}

		else if (!thumbnail->getSprite().getGlobalBounds().contains(mousePos) && thumbnail->getHighlightColour() == this->buttonHighlightedColour)
		{
			thumbnail->setHighlightColour(this->buttonColour);

			if (!thumbnail->getIsShrinking())
			{
				thumbnail->setIsEnlarging(false);
				thumbnail->setIsShrinking(true);
			}

		}

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
	for (BaseGameThumbnails* thumbnail : thumbnails)
	{
		thumbnail->render(target);
	}

	target.draw(this->backButton);
}
