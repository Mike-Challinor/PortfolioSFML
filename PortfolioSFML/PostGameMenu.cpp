#include "PostGameMenu.h"

//PRIVATE FUNCTIONS

void PostGameMenu::initVar(sf::VideoMode screen_bounds)
{
	this->menuOpen = false;
	this->mouseHeld = false;
	this->userSelection = 0;
	this->screenBounds = screen_bounds;
	this->textField = new Textfield(this->screenBounds);
}

void PostGameMenu::initFont(sf::Font font)
{
	this->font = font;
}

void PostGameMenu::initGUI()
{
	//Init menu panel
	this->menuPanel.setFillColor(sf::Color(177, 177, 177));
	this->menuPanel.setSize(sf::Vector2f(this->screenBounds.width - 100.f, this->screenBounds.height / 2.5));
	this->menuPanel.setPosition(this->screenBounds.width / 2 - this->menuPanel.getGlobalBounds().width / 2, this->screenBounds.height / 2 - this->menuPanel.getGlobalBounds().height / 2);
}

void PostGameMenu::initButtons()
{
	//Init button colour
	this->buttonColour = sf::Color::White;
	this->buttonHighlightedColour = sf::Color::Yellow;

	//Init Play button
	this->playButton.setFillColor(this->buttonColour);
	this->playButton.setSize(sf::Vector2f(180.f, 50.f));
	this->playButton.setPosition(this->screenBounds.width / 3 - this->playButton.getGlobalBounds().width, this->screenBounds.height / 2 - this->playButton.getGlobalBounds().height / 2);

	//Init Enter Score button
	this->enterScoreButton.setFillColor(this->buttonColour);
	this->enterScoreButton.setSize(sf::Vector2f(180.f, 50.f));
	this->enterScoreButton.setPosition(this->screenBounds.width / 2 - this->playButton.getGlobalBounds().width / 2, this->screenBounds.height / 2 - this->playButton.getGlobalBounds().height / 2);

	//Init Exit button
	this->exitButton.setFillColor(this->buttonColour);
	this->exitButton.setSize(sf::Vector2f(180.f, 50.f));
	this->exitButton.setPosition(this->screenBounds.width - this->screenBounds.width / 3, this->screenBounds.height / 2 - this->playButton.getGlobalBounds().height / 2);
}

void PostGameMenu::initText()
{
	//Title Text Init
	this->menuTitleText.setFont(this->font);
	this->menuTitleText.setCharacterSize(64);
	this->menuTitleText.setFillColor(sf::Color::White);
	this->menuTitleText.setString("Game Over!");
	this->menuTitleText.setPosition(this->screenBounds.width / 2 - this->menuTitleText.getGlobalBounds().width / 2, 20.f);

	//Play Text Init
	this->playButtonText.setFont(this->font);
	this->playButtonText.setCharacterSize(24);
	this->playButtonText.setFillColor(sf::Color::Black);
	this->playButtonText.setString("Play again");
	this->playButtonText.setPosition(this->playButton.getGlobalBounds().left + this->playButton.getGlobalBounds().width / 2 - this->playButtonText.getGlobalBounds().width / 2, this->playButton.getGlobalBounds().top + this->playButton.getGlobalBounds().height / 2 - this->playButtonText.getGlobalBounds().height / 1.2);

	this->scoreButtonText.setFont(this->font);
	this->scoreButtonText.setCharacterSize(24);
	this->scoreButtonText.setFillColor(sf::Color::Black);
	this->scoreButtonText.setString("Add Score");
	this->scoreButtonText.setPosition(this->enterScoreButton.getGlobalBounds().left + this->enterScoreButton.getGlobalBounds().width / 2 - this->scoreButtonText.getGlobalBounds().width / 2, this->enterScoreButton.getGlobalBounds().top + this->enterScoreButton.getGlobalBounds().height / 2 - this->scoreButtonText.getGlobalBounds().height / 1.2);

	this->exitButtonText.setFont(this->font);
	this->exitButtonText.setCharacterSize(24);
	this->exitButtonText.setFillColor(sf::Color::Black);
	this->exitButtonText.setString("Exit");
	this->exitButtonText.setPosition(this->exitButton.getGlobalBounds().left + this->exitButton.getGlobalBounds().width / 2 - this->exitButtonText.getGlobalBounds().width / 2, this->exitButton.getGlobalBounds().top + this->exitButton.getGlobalBounds().height / 2 - this->exitButtonText.getGlobalBounds().height / 1.2);
}

//CONSTRUCTORS AND DESTRUCTORS

PostGameMenu::PostGameMenu(sf::Font font, sf::VideoMode screen_bounds)
{
	this->initVar(screen_bounds);
	this->initGUI();
	this->initButtons();
	this->initFont(font);
	this->initText();
}

PostGameMenu::~PostGameMenu()
{
	delete this->textField;
}

//PUBLIC FUNCTIONS

void PostGameMenu::menuInteraction(sf::Vector2f mouse_pos)
{
	//Check for button presses.
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{

			this->mouseHeld = true;

			//If textfield has not been opened.
			if (this->addingScore == false)

			{
				if (this->playButton.getGlobalBounds().contains(mouse_pos))
				{
					std::cout << "Play pressed" << std::endl;
					this->userSelection = 1;
				}

				else if (this->enterScoreButton.getGlobalBounds().contains(mouse_pos))
				{
					std::cout << "Enter Score pressed" << std::endl;
					this->addingScore = true;
					this->userSelection = 2;
				}

				else if (this->exitButton.getGlobalBounds().contains(mouse_pos))
				{
					std::cout << "Exit pressed" << std::endl;
					this->userSelection = 3;
				}
			}

			else
			{

			}

		}

	}

	else
	{
		this->mouseHeld = false;
	}
}

//ACCESSORS

const bool PostGameMenu::getMenuOpen() const
{
	return this->menuOpen;
}

const int PostGameMenu::getUserSelection() const
{
	return this->userSelection;
}

const bool PostGameMenu::getAddingScore() const
{
	return this->addingScore;
}

//MODIFIERS

void PostGameMenu::setMenuOpen(bool is_open)
{
	this->menuOpen = is_open;
}

void PostGameMenu::setString(char character)
{
	this->textField->setString(character);
}

void PostGameMenu::setAddingScore(bool isAddingScore)
{
	this->addingScore = isAddingScore;
}

//UPDATES

void PostGameMenu::update(sf::Vector2f mouse_pos)
{
	if (this->addingScore == false)
	{
		this->updateGUI(mouse_pos);
	}

	else
	{
		this->textField->update();
	}
	
}

void PostGameMenu::updateGUI(sf::Vector2f mouse_pos)
{
	if (this->playButton.getGlobalBounds().contains(mouse_pos) && this->playButton.getFillColor() == this->buttonColour)
	{
		this->playButton.setFillColor(this->buttonHighlightedColour);
	}

	else if (!this->playButton.getGlobalBounds().contains(mouse_pos) && this->playButton.getFillColor() == this->buttonHighlightedColour)
	{
		this->playButton.setFillColor(this->buttonColour);
	}

	if (this->enterScoreButton.getGlobalBounds().contains(mouse_pos) && this->enterScoreButton.getFillColor() == this->buttonColour)
	{
		this->enterScoreButton.setFillColor(this->buttonHighlightedColour);
	}

	else if (!this->enterScoreButton.getGlobalBounds().contains(mouse_pos) && this->enterScoreButton.getFillColor() == this->buttonHighlightedColour)
	{
		this->enterScoreButton.setFillColor(this->buttonColour);
	}

	if (this->exitButton.getGlobalBounds().contains(mouse_pos) && this->exitButton.getFillColor() == this->buttonColour)
	{
		this->exitButton.setFillColor(this->buttonHighlightedColour);
	}

	else if (!this->exitButton.getGlobalBounds().contains(mouse_pos) && this->exitButton.getFillColor() == this->buttonHighlightedColour)
	{
		this->exitButton.setFillColor(this->buttonColour);
	}
}

//RENDERS

void PostGameMenu::render(sf::RenderTarget& target)
{
	this->renderGUI(target);

	if (this->addingScore)
	{
		this->textField->render(target);
	}
}

void PostGameMenu::renderGUI(sf::RenderTarget& target)
{
	this->renderPanels(target);
	this->renderButtons(target);
	this->renderText(target);
}

void PostGameMenu::renderPanels(sf::RenderTarget& target)
{
	target.draw(this->menuPanel);
}

void PostGameMenu::renderButtons(sf::RenderTarget& target)
{
	target.draw(this->playButton);
	target.draw(this->enterScoreButton);
	target.draw(this->exitButton);
}

void PostGameMenu::renderText(sf::RenderTarget& target)
{
	target.draw(this->menuTitleText);
	target.draw(this->playButtonText);
	target.draw(this->scoreButtonText);
	target.draw(this->exitButtonText);
}

