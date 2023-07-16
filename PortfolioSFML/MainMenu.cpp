#include "MainMenu.h"
#include "BoxClicker.h"

#include <iostream>

void MainMenu::initVar()
{
	this->mainMenuOpen = true;
	this->mouseHeld = false;
}

void MainMenu::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Simple Games", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void MainMenu::initFont()
{
	if (!this->font.loadFromFile("Fonts/Motley.ttf"))
	{
		std::cout << "ERROR::MAINMENU::INITFONT:: Unable to load Motley.ttf" << std::endl;
	}
}

void MainMenu::initText()
{
	//titleText Text Init
	this->titleText.setFont(this->font);
	this->titleText.setCharacterSize(64);
	this->titleText.setFillColor(sf::Color::White);
	this->titleText.setString("Main Menu");
	this->titleText.setPosition(sf::Vector2f(static_cast<float>(this->window->getSize().x / 2) - static_cast<float>(this->titleText.getGlobalBounds().width / 2), 20.f));

	//Play Text Init
	this->playButtonText.setFont(this->font);
	this->playButtonText.setCharacterSize(32);
	this->playButtonText.setFillColor(sf::Color::Black);
	this->playButtonText.setString("Play");
	this->playButtonText.setPosition(this->playButton.getPosition().x + (this->playButton.getGlobalBounds().width / 2) - (playButtonText.getGlobalBounds().width / 2), this->playButton.getPosition().y + (this->playButton.getGlobalBounds().height / 2) - (playButtonText.getGlobalBounds().height / 1.2));

	//Quit Text Init
	this->quitButtonText.setFont(this->font);
	this->quitButtonText.setCharacterSize(32);
	this->quitButtonText.setFillColor(sf::Color::Black);
	this->quitButtonText.setString("Quit");
	this->quitButtonText.setPosition(this->quitButton.getPosition().x + (this->quitButton.getGlobalBounds().width / 2) - (quitButtonText.getGlobalBounds().width / 2), this->quitButton.getPosition().y + (this->quitButton.getGlobalBounds().height / 2) - (quitButtonText.getGlobalBounds().height / 1.2));

}

void MainMenu::initButtons()
{
	//Init play button
	this->playButton.setSize(sf::Vector2f(200.f, 50.f));
	this->playButton.setFillColor(sf::Color::White);
	this->playButton.setPosition(sf::Vector2f(static_cast<float>(this->window->getSize().x / 2) - static_cast<float>(this->playButton.getGlobalBounds().width / 2), static_cast<float>(this->window->getSize().y / 2) - static_cast<float>(this->playButton.getGlobalBounds().height)));

	//Init quit button
	this->quitButton.setSize(sf::Vector2f(200.f, 50.f));
	this->quitButton.setFillColor(sf::Color::White);
	this->quitButton.setPosition(sf::Vector2f(static_cast<float>(this->window->getSize().x / 2) - static_cast<float>(this->quitButton.getGlobalBounds().width / 2), static_cast<float>(this->window->getSize().y / 2) + static_cast<float>(this->quitButton.getGlobalBounds().height)));
}



MainMenu::MainMenu()
{
	this->initWindow();
	this->initFont();
	this->initButtons();
	this->initText();
}

MainMenu::~MainMenu()
{
	delete this->window;
}

const bool MainMenu::applicationRunning() const
{
	return this->window->isOpen();
}

const bool MainMenu::mainMenuRunning() const
{
	return mainMenuOpen;
}

void MainMenu::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->mainMenuOpen = false;
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
			{
				this->mainMenuOpen = false;
				this->window->close();				
			}
			break;
		}
	}
}

void MainMenu::update()
{
	this->pollEvents();

	this->updateMousePosition();

	//Check for button presses.
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{

			this->mouseHeld = true;

			if (this->playButton.getGlobalBounds().contains(this->mousePosView))
			{
				std::cout << "Play!" << std::endl;
				this->mainMenuOpen = false;
				BoxClicker boxClicker;
			}

			else if (this->quitButton.getGlobalBounds().contains(this->mousePosView))
			{
				this->mainMenuOpen = false;
				this->window->close();
			}
		}

	}

	else
	{
		this->mouseHeld = false;
	}
}

void MainMenu::updateGUI()
{

}

void MainMenu::updateMousePosition()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void MainMenu::render()
{
	
	if (this->mainMenuOpen)
	{
		//Clear the window
		this->window->clear();

		//Render stuff
		this->renderGUI(this->window);

		this->window->display();
	}
	
}

void MainMenu::renderGUI(sf::RenderTarget* target)
{
	target->draw(this->playButton);
	target->draw(this->quitButton);

	target->draw(this->titleText);
	target->draw(this->playButtonText);
	target->draw(this->quitButtonText);
}
