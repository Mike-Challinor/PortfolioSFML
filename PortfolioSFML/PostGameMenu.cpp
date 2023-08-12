#include "PostGameMenu.h"

//PRIVATE FUNCTIONS

void PostGameMenu::initVar(sf::VideoMode screen_bounds, int game_num, std::vector<std::pair<std::string, unsigned>> scores_vec)
{
	this->scores = scores_vec;
	this->scoreEntered = false;
	this->gameNum = game_num;
	this->menuOpen = false;
	this->mouseHeld = false;
	this->userSelection = 0;
	this->screenBounds = screen_bounds;
	this->textField = new Textfield(this->screenBounds);


	//Loop through vector of scores and update each text
	for (const auto& pair : this->scores)
	{
		this->namesString += pair.first;
		this->namesString += "\n";

		this->scoresString += std::to_string(pair.second);
		this->scoresString += "\n";
	}

}

void PostGameMenu::initFont(sf::Font font)
{
	this->font = font;
}

void PostGameMenu::initGUI()
{
	//Init menu panel
	this->menuPanel.setFillColor(sf::Color(177, 177, 177));
	this->menuPanel.setSize(sf::Vector2f(this->screenBounds.width / 2 - 20.f, this->screenBounds.height / 1.2));
	this->menuPanel.setPosition(10.f, this->screenBounds.height / 2 - this->menuPanel.getGlobalBounds().height / 4);
	//Init menu panel
	this->leaderBoardPanel.setFillColor(sf::Color(177, 177, 177));
	this->leaderBoardPanel.setSize(sf::Vector2f(this->screenBounds.width / 2 - 20.f, this->screenBounds.height / 1.2));
	this->leaderBoardPanel.setPosition(this->screenBounds.width / 2 + 10.f, this->screenBounds.height / 2 - this->menuPanel.getGlobalBounds().height / 4);
}

void PostGameMenu::initButtons()
{
	//Init button colour
	this->buttonColour = sf::Color::White;
	this->buttonHighlightedColour = sf::Color::Yellow;

	//Init Enter Score button
	this->enterScoreButton.setFillColor(this->buttonColour);
	this->enterScoreButton.setSize(sf::Vector2f(180.f, 50.f));
	this->enterScoreButton.setPosition(this->menuPanel.getGlobalBounds().left + this->menuPanel.getGlobalBounds().width / 2 - this->enterScoreButton.getGlobalBounds().width / 2, this->menuPanel.getGlobalBounds().top + this->menuPanel.getGlobalBounds().height / 2 - this->enterScoreButton.getGlobalBounds().height);

	//Init Play button
	this->playButton.setFillColor(this->buttonColour);
	this->playButton.setSize(sf::Vector2f(180.f, 50.f));
	this->playButton.setPosition(this->menuPanel.getGlobalBounds().left + this->menuPanel.getGlobalBounds().width / 2 - this->playButton.getGlobalBounds().width / 2, this->enterScoreButton.getGlobalBounds().top - this->playButton.getGlobalBounds().height * 1.5);
	
	//Init Exit button
	this->exitButton.setFillColor(this->buttonColour);
	this->exitButton.setSize(sf::Vector2f(180.f, 50.f));
	this->exitButton.setPosition(this->menuPanel.getGlobalBounds().left + this->menuPanel.getGlobalBounds().width / 2 - this->exitButton.getGlobalBounds().width / 2, this->enterScoreButton.getGlobalBounds().top + this->exitButton.getGlobalBounds().height * 1.5);

}

void PostGameMenu::initText()
{
	//Title Text Init
	this->menuTitleText.setFont(this->font);
	this->menuTitleText.setCharacterSize(64);
	this->menuTitleText.setFillColor(sf::Color::White);
	this->menuTitleText.setString("Game Over!");
	this->menuTitleText.setPosition(this->screenBounds.width / 2 - this->menuTitleText.getGlobalBounds().width / 2, 20.f);

	//Leaderboard title text init
	this->leaderboardTitleText.setFont(this->font);
	this->leaderboardTitleText.setCharacterSize(28);
	this->leaderboardTitleText.setFillColor(sf::Color::White);
	this->leaderboardTitleText.setString("Leaderboard");
	this->leaderboardTitleText.setPosition(this->leaderBoardPanel.getGlobalBounds().left + this->leaderBoardPanel.getGlobalBounds().width / 2 - this->leaderboardTitleText.getGlobalBounds().width / 2, this->leaderBoardPanel.getGlobalBounds().top + 10.f);

	//Play button Text Init
	this->playButtonText.setFont(this->font);
	this->playButtonText.setCharacterSize(24);
	this->playButtonText.setFillColor(sf::Color::Black);
	this->playButtonText.setString("Play again");
	this->playButtonText.setPosition(this->playButton.getGlobalBounds().left + this->playButton.getGlobalBounds().width / 2 - this->playButtonText.getGlobalBounds().width / 2, this->playButton.getGlobalBounds().top + this->playButton.getGlobalBounds().height / 2 - this->playButtonText.getGlobalBounds().height / 1.2);

	//Score button text init
	this->scoreButtonText.setFont(this->font);
	this->scoreButtonText.setCharacterSize(24);
	this->scoreButtonText.setFillColor(sf::Color::Black);
	this->scoreButtonText.setString("Add Score");
	this->scoreButtonText.setPosition(this->enterScoreButton.getGlobalBounds().left + this->enterScoreButton.getGlobalBounds().width / 2 - this->scoreButtonText.getGlobalBounds().width / 2, this->enterScoreButton.getGlobalBounds().top + this->enterScoreButton.getGlobalBounds().height / 2 - this->scoreButtonText.getGlobalBounds().height / 1.2);

	//Exit button text init
	this->exitButtonText.setFont(this->font);
	this->exitButtonText.setCharacterSize(24);
	this->exitButtonText.setFillColor(sf::Color::Black);
	this->exitButtonText.setString("Exit");
	this->exitButtonText.setPosition(this->exitButton.getGlobalBounds().left + this->exitButton.getGlobalBounds().width / 2 - this->exitButtonText.getGlobalBounds().width / 2, this->exitButton.getGlobalBounds().top + this->exitButton.getGlobalBounds().height / 2 - this->exitButtonText.getGlobalBounds().height / 1.2);

	//Names text init
	this->namesText.setFont(this->font);
	this->namesText.setCharacterSize(28);
	this->namesText.setFillColor(sf::Color::Blue);
	this->namesText.setString(this->namesString);
	this->namesText.setPosition(this->leaderBoardPanel.getGlobalBounds().left + 5.f, this->leaderBoardPanel.getGlobalBounds().top + 5.f);

	//Scores text init
	this->scoresText.setFont(this->font);
	this->scoresText.setCharacterSize(28);
	this->scoresText.setFillColor(sf::Color::Blue);
	this->scoresText.setString(this->scoresString);

	this->namesText.setPosition(this->leaderBoardPanel.getGlobalBounds().left + this->leaderBoardPanel.getGlobalBounds().width / 2 - this->namesText.getGlobalBounds().width, this->leaderboardTitleText.getGlobalBounds().top + this->leaderboardTitleText.getGlobalBounds().height * 2);
	this->scoresText.setPosition(this->leaderBoardPanel.getGlobalBounds().left + this->leaderBoardPanel.getGlobalBounds().width / 2 + this->scoresText.getGlobalBounds().width / 2, this->leaderboardTitleText.getGlobalBounds().top + this->leaderboardTitleText.getGlobalBounds().height * 2);

	while (this->namesText.getGlobalBounds().left <= this->leaderBoardPanel.getGlobalBounds().left + 5.f)
	{
		this->namesText.setCharacterSize(this->namesText.getCharacterSize() - 1);
		this->scoresText.setCharacterSize(this->scoresText.getCharacterSize() - 1);
		this->namesText.setPosition(this->leaderBoardPanel.getGlobalBounds().left + this->leaderBoardPanel.getGlobalBounds().width / 2 - this->namesText.getGlobalBounds().width, this->leaderboardTitleText.getGlobalBounds().top + this->leaderboardTitleText.getGlobalBounds().height * 2);
		this->scoresText.setPosition(this->leaderBoardPanel.getGlobalBounds().left + this->leaderBoardPanel.getGlobalBounds().width / 2 + this->scoresText.getGlobalBounds().width / 2, this->leaderboardTitleText.getGlobalBounds().top + this->leaderboardTitleText.getGlobalBounds().height * 2);
	}

}

//CONSTRUCTORS AND DESTRUCTORS

PostGameMenu::PostGameMenu(sf::Font font, sf::VideoMode screen_bounds, int game_num, std::vector<std::pair<std::string, unsigned>> scores_vec)
{
	this->initVar(screen_bounds, game_num, scores_vec);
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
				if (this->textField->getShape().getGlobalBounds().contains(mouse_pos))
				{
					this->textField->setInFocus(true);
				}

				else
				{
					this->textField->setInFocus(false);
				}
			}

		}

	}

	else
	{
		this->mouseHeld = false;
	}
}

void PostGameMenu::removeChar()
{
	this->textField->removeChar();
}

void PostGameMenu::closeMenu()
{
	this->scoreEntered = false;
	this->menuOpen = false;
	this->mouseHeld = false;
	this->userSelection = 0;
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

const bool PostGameMenu::textFieldInFocus() const
{
	return this->textField->getInFocus();
}

const bool PostGameMenu::getScoreEntered() const
{
	return this->scoreEntered;
}

const std::string PostGameMenu::getName() const
{
	return this->textField->getString();
}


//MODIFIERS

void PostGameMenu::setMenuOpen(bool is_open)
{
	this->menuOpen = is_open;
}

void PostGameMenu::addChar(char character)
{
	this->textField->addChar(character);
}

void PostGameMenu::setAddingScore(bool isAddingScore)
{
	this->addingScore = isAddingScore;
}

void PostGameMenu::setTextFieldFocus(bool in_focus)
{
	this->textField->setInFocus(in_focus);
}

void PostGameMenu::setScoreEntered(bool score_entered)
{
	this->scoreEntered = score_entered;
}

void PostGameMenu::setScores(std::vector<std::pair<std::string, unsigned>> scores_vec)
{
	this->scores = scores_vec;
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
		this->textField->update(mouse_pos);

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
	target.draw(this->leaderBoardPanel);
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
	target.draw(this->leaderboardTitleText);
	target.draw(this->playButtonText);
	target.draw(this->scoreButtonText);
	target.draw(this->exitButtonText);
	target.draw(this->namesText);
	target.draw(this->scoresText);
}

