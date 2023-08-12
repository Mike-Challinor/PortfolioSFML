#include "MainMenu.h"

#include <iostream>

void MainMenu::initVar()
{
	this->mainMenuOpen = true;
	this->mouseHeld = false;

	//Init classes
	this->leaderboards = new Leaderboards();
}

void MainMenu::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window.create(this->videoMode, "Simple Games", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void MainMenu::initBackground()
{
	//Load the texture
	if (!this->backgroundTexture.loadFromFile("Resources/Textures/menuBackground.png"))
	{
		std::cout << "ERROR::MAINMENU::INITBACKGROUND:: Unable to load backgroundTexture.png" << std::endl;
	}

	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.setScale(1, 1);
}

void MainMenu::initFont()
{
	if (!this->font.loadFromFile("Resources/Fonts/Motley.ttf"))
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
	this->titleText.setPosition(sf::Vector2f(static_cast<float>(this->window.getSize().x / 2) - static_cast<float>(this->titleText.getGlobalBounds().width / 2), 20.f));

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
	//Init button colours
	this->buttonColour = sf::Color::White;
	this->buttonHighlightedColour = sf::Color::Yellow;

	//Init play button
	this->playButton.setSize(sf::Vector2f(200.f, 50.f));
	this->playButton.setFillColor(this->buttonColour);
	this->playButton.setPosition(sf::Vector2f(static_cast<float>(this->window.getSize().x / 2) - static_cast<float>(this->playButton.getGlobalBounds().width / 2), static_cast<float>(this->window.getSize().y / 2) - static_cast<float>(this->playButton.getGlobalBounds().height)));

	//Init quit button
	this->quitButton.setSize(sf::Vector2f(200.f, 50.f));
	this->quitButton.setFillColor(this->buttonColour);
	this->quitButton.setPosition(sf::Vector2f(static_cast<float>(this->window.getSize().x / 2) - static_cast<float>(this->quitButton.getGlobalBounds().width / 2), static_cast<float>(this->window.getSize().y / 2) + static_cast<float>(this->quitButton.getGlobalBounds().height)));
}

void MainMenu::initSubMenus()
{
	this->gamesMenu = new GamesMenu(this->font, this->videoMode);
	this->pauseMenu = new PauseMenu(this->font, this->videoMode);
	this->leaderboardMenu = new LeaderboardMenu();
}

void MainMenu::initBoxClicker()
{
	this->leaderboardMenu->readScores(1);
	this->boxClicker = new BoxClicker(this->font, this->videoMode, this->leaderboards);
	this->boxClicker->setScores(this->leaderboardMenu->getScores(1));
	gameState.setCurrentGameState(1);
}

void MainMenu::mainMenuInteraction()
{

	//Check for button presses.
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{

			this->mouseHeld = true;

			if (this->playButton.getGlobalBounds().contains(this->mousePosView))
			{
				this->mainMenuOpen = false;
				this->window.clear();
				this->window.display();
				this->gamesMenu->setMenuOpen(true);

			}

			else if (this->quitButton.getGlobalBounds().contains(this->mousePosView))
			{
				std::cout << "Quit";
				this->mainMenuOpen = false;
				this->window.close();
			}
		}

	}

	else
	{
		this->mouseHeld = false;
	}

}

void MainMenu::gameOver()
{

	//Ending Game
	this->isBoxClickerLaunched = false;
	this->gamesMenu->setBoxClickerLaunched(false);
	this->displayClear();
	this->displayRender();

	//Set game state to main menu.
	this->gameState.setCurrentGameState(0);

	//Open the games menu.
	this->gamesMenu->setMenuOpen(true);

}

void MainMenu::endBoxClicker()
{
	delete this->boxClicker;
}



MainMenu::MainMenu(GameState& gameState) : gameState(gameState)
{
	this->initVar();
	this->initWindow();
	this->initBackground();
	this->initFont();
	this->initButtons();
	this->initText();
	this->initSubMenus();
}

MainMenu::~MainMenu()
{
	if (boxClicker != NULL)
	{
		delete this->boxClicker;
	}

	if (gamesMenu != NULL)
	{
		delete this->gamesMenu;
	}
	
}

const bool MainMenu::applicationRunning() const
{
	return this->window.isOpen();
}

const bool MainMenu::mainMenuRunning() const
{
	return this->mainMenuOpen;
}

const sf::RenderWindow& MainMenu::getWindow() const
{
	return this->window;
}

BoxClicker* MainMenu::getBoxClicker()
{
	return this->boxClicker;
}

bool MainMenu::hasBoxClickerEnded()
{
	return this->boxClicker->getEndGame();
}

void MainMenu::displayRender()
{
	this->window.display();
}

void MainMenu::displayClear()
{
	this->window.clear();
}


void MainMenu::pollEvents()
{

	while (this->window.pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->mainMenuOpen = false;
			this->window.close();
			break;

		case sf::Event::KeyPressed:
			
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
			{
				if (this->mainMenuOpen)
				{
					this->mainMenuOpen = false;
					this->window.close();
				}

				else if (this->gamesMenu->getMenuOpen())
				{
					this->gamesMenu->setMenuOpen(false);
					this->mainMenuOpen = true;
				}

				else if (this->isBoxClickerLaunched)
				{

					if (!this->boxClicker->getIsPostGame())
					{
						if (this->pauseMenu->getPaused())
						{
							this->pauseMenu->setPaused(false);
						}

						else
						{
							this->pauseMenu->setPaused(true);
						}
					}

					else
					{
						if (this->boxClicker->getAddingScore())
						{
							if (this->boxClicker->textFieldInFocus())
							{
								this->boxClicker->setTextFieldFocus(false);
							}

							else if (!this->boxClicker->textFieldInFocus())
							{
								this->boxClicker->setAddingScore(false);
							}
						}

						else
						{
							this->boxClicker->setEndGame(true);
						}
					}
				}			
			}

			else if (this->sfmlEvent.key.code == sf::Keyboard::BackSpace)
			{
				if (this->isBoxClickerLaunched)
				{
					if (this->boxClicker->getIsPostGame())
					{
						if (this->boxClicker->textFieldInFocus())
						{
							this->boxClicker->removeChar();
						}
					}
				}
			}

			else if (this->sfmlEvent.key.code == sf::Keyboard::Enter)
			{
				if (this->isBoxClickerLaunched && this->boxClicker->getIsPostGame() && this->boxClicker->getAddingScore() && this->boxClicker->textFieldInFocus())
				{
					this->boxClicker->setScoreEntered(true);
				}
			}


			else if (this->sfmlEvent.key.code == sf::Keyboard::Tab)
			{
				this->leaderboardMenu->readScores(1);
				this->leaderboardMenu->printScores(1);
			}
			break;


		case sf::Event::TextEntered:
			{

				if (this->boxClicker != NULL)
				{
					if (this->boxClicker->getIsPostGame() && this->boxClicker->getAddingScore())
					{
						if (this->sfmlEvent.text.unicode >= 65 && this->sfmlEvent.text.unicode <= 90 || this->sfmlEvent.text.unicode >= 97 && this->sfmlEvent.text.unicode <= 122)
						{
							char character = static_cast<char>(this->sfmlEvent.text.unicode);
							this->boxClicker->addChar(character);
						}
					}
				}
			}

			break;
		}
	}
}

void MainMenu::update()
{
	this->updateMousePosition();
	
	if (this->mainMenuOpen)
	{
		this->mainMenuInteraction();
		this->updateGUI();
	}

	else if (this->gamesMenu->getMenuOpen())
	{
		this->gamesMenu->update(this->mousePosView);
		this->gamesMenu->menuInteraction(mousePosView);
		
		if (this->gamesMenu->getBoxClickerLaunched())
		{
			this->isBoxClickerLaunched = true;
			this->initBoxClicker();
		}
	}

	else
	{
		this->mainMenuOpen = true;
		this->mainMenuInteraction();
		this->updateGUI();
	}	
	
}

void MainMenu::updateBoxClicker()
{

	if (this->isBoxClickerLaunched && this->hasBoxClickerEnded())
	{
		this->gameOver();
	}

	else
	{

		if (pauseMenu->getPaused())
		{
			this->updatePauseMenu();
		}

		else
		{
			this->boxClicker->update(this->mousePosView);
		}
	}


	
}



void MainMenu::updateGUI()
{
	if (this->quitButton.getGlobalBounds().contains(this->mousePosView) && this->quitButton.getFillColor() == this->buttonColour)
	{
		this->quitButton.setFillColor(this->buttonHighlightedColour);
	}

	else if (!this->quitButton.getGlobalBounds().contains(this->mousePosView) && this->quitButton.getFillColor() == this->buttonHighlightedColour)
	{
		this->quitButton.setFillColor(this->buttonColour);
	}

	if (this->playButton.getGlobalBounds().contains(this->mousePosView) && this->playButton.getFillColor() == this->buttonColour)
	{
		this->playButton.setFillColor(this->buttonHighlightedColour);
	}

	else if (!this->playButton.getGlobalBounds().contains(this->mousePosView) && this->playButton.getFillColor() == this->buttonHighlightedColour)
	{
		this->playButton.setFillColor(this->buttonColour);
	}
	
}

void MainMenu::updateMousePosition()
{
	this->mousePosWindow = sf::Mouse::getPosition(this->window);
	this->mousePosView = this->window.mapPixelToCoords(this->mousePosWindow);
}

void MainMenu::updatePauseMenu()
{
	this->pauseMenu->menuInteraction(this->mousePosView);
	this->pauseMenu->update(this->mousePosView);

	if (this->pauseMenu->getHasQuit())
	{
		this->window.close();
	}
}

void MainMenu::render()
{
	
	//Clear the window
	this->window.clear();

	if (this->mainMenuOpen)
	{
		//Render stuff
		this->renderGUI(this->window);
	}

	else if (this->gamesMenu->getMenuOpen())
	{
		this->gamesMenu->render(this->window);
	}


	//Display the window
	this->window.display();
	
}

void MainMenu::renderBoxClicker()
{
	this->boxClicker->render(this->window);

	if (this->pauseMenu->getPaused())
	{
		this->pauseMenu->render(this->window);
	}
}

void MainMenu::renderGUI(sf::RenderTarget& target)
{
	target.draw(this->backgroundSprite);
	target.draw(this->playButton);
	target.draw(this->quitButton);
	target.draw(this->titleText);
	target.draw(this->playButtonText);
	target.draw(this->quitButtonText);
	
}
