#include "BaseGame.h"

void BaseGame::initGame(sf::Font font, sf::VideoMode screen_bounds, Leaderboards* leader_board)
{
	this->initVar(screen_bounds, leader_board);
    this->initFonts(font);
    this->initText();
}

void BaseGame::initVar(sf::VideoMode screen_bounds, Leaderboards* leader_board)
{
	this->isPostGame = false;
	this->addingScore = false;
	this->endGame = false;
	this->screenBounds = screen_bounds;
	this->leaderboard = leader_board;

	this->initGameVars();
}

void BaseGame::initGameVars()
{

}

void BaseGame::initFonts(sf::Font font)
{
	this->font = font;
}

void BaseGame::initText()
{

}

void BaseGame::restartGame()
{

}

void BaseGame::callPostGame()
{
    //Open post game menu
    if (this->postGameMenu == nullptr)
    {
        this->postGameMenu = new PostGameMenu(this->font, this->screenBounds, this->gameNum, this->scores);
        this->isPostGame = true;
    }
}

BaseGame::BaseGame()
{
    
}

BaseGame::~BaseGame()
{
    if (this->postGameMenu != nullptr)
    {
        delete this->postGameMenu;
        this->postGameMenu = nullptr;
    }
}

const bool BaseGame::getEndGame() const
{
	return this->endGame;
}

const unsigned BaseGame::getScore() const
{
    return this->points;
}

const bool BaseGame::getAddingScore() const
{
	return this->postGameMenu->getAddingScore();
}

const bool BaseGame::textFieldInFocus() const
{
	return this->postGameMenu->textFieldInFocus();
}

const bool BaseGame::getIsPostGame() const
{
	return this->isPostGame;
}

void BaseGame::addChar(char character)
{
	this->postGameMenu->addChar(character);
}

void BaseGame::setAddingScore(bool isAddingScore)
{
	this->postGameMenu->setAddingScore(isAddingScore);
}

void BaseGame::setEndGame(bool end_game)
{
	this->endGame = end_game;
}

void BaseGame::setTextFieldFocus(bool in_focus)
{
	this->postGameMenu->setTextFieldFocus(in_focus);
}

void BaseGame::setLeaderboard(Leaderboards* leaderboard)
{
	this->leaderboard = leaderboard;
}

void BaseGame::setScoreEntered(bool score_entered)
{
	this->postGameMenu->setScoreEntered(score_entered);
}

void BaseGame::setScores(std::vector<std::pair<std::string, unsigned>> scores_vec)
{
    if (scores_vec.empty())
    {
        std::cout << "Score vec is empty" << std::endl;
    }

    else
    {
        std::cout << "TASK::BASEGAME::SETSCORES::The size of the scores vector before setting is: " << scores_vec.size() << std::endl; 
        this->scores = scores_vec;
        std::cout << "TASK::BASEGAME::SETSCORES::The size of the scores vector after setting is: " << this->scores.size() << std::endl;
    }
	
}

void BaseGame::updateMousePositions(sf::Vector2f mousePos)
{
	this->mousePosView = mousePos;
}

void BaseGame::removeChar()
{
	this->postGameMenu->removeChar();
}

void BaseGame::update()
{

}

void BaseGame::updateGame(sf::Vector2f mouse_pos)
{
    if (this->isPostGame == false)
    {
        this->updateMousePositions(mouse_pos);
        this->update();
    }

    else
    {

        switch (this->postGameMenu->getUserSelection())
        {
            //Nothing selected
        case 0:
            this->postGameMenu->update(mouse_pos);
            this->postGameMenu->menuInteraction(mouse_pos);
            break;

            //Play again selected
        case 1:
            this->restartGame();
            break;

            //Add score selected
        case 2:
            this->postGameMenu->update(mouse_pos);
            this->postGameMenu->menuInteraction(mouse_pos);

            if (this->postGameMenu->getScoreEntered())
            {
                if (this->leaderboard == NULL)
                {
                    std::cout << "leaderboard is null" << std::endl;
                }

                else
                {
                    std::cout << "Score has been entered" << std::endl;
                    this->leaderboard->addScore(this->postGameMenu->getName(), this->getScore(), this->gameNum);
                    this->postGameMenu->closeMenu();
                    this->endGame = true;
                }


            }
            break;

            //Quit selected
        case 3:
            this->endGame = true;
            break;
        }

    }

}

void BaseGame::renderGame(sf::RenderTarget& target)
{
    target.clear();
    this->render(target);

    if (this->isPostGame)
    {
        //Render post game screen
        this->postGameMenu->render(target);
    }
}

void BaseGame::render(sf::RenderTarget& target)
{

}
