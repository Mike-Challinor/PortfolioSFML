#include "BoxClicker.h"
#include "MainMenu.h"


//Private functions
void BoxClicker::initVar(sf::VideoMode screen_bounds)
{
    this->isPostGame = false;
    this->addingScore = false;

    //BoxClicker logic
    this->endGame = false;
    this->points = 0;
    this->health = 20;
    this->enemySpawnTimerMax = 20.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 7;
    this->mouseHeld = false;
    this->screenBounds = screen_bounds;

}

void BoxClicker::initFonts(sf::Font font)
{
    this->font = font;
}

void BoxClicker::initText()
{
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(24);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("NONE");
}

void BoxClicker::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);

}

void BoxClicker::restartGame()
{
    this->isPostGame = false;
    this->addingScore = false;

    //BoxClicker logic
    this->points = 0;
    this->health = 20;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->mouseHeld = false;
    this->enemies.clear();
}

//Constructors / Destructors
BoxClicker::BoxClicker(sf::Font font, sf::VideoMode screen_bounds)
{
    this->initVar(screen_bounds);
    this->initFonts(font);
    this->initText();
    this->initEnemies();
}

BoxClicker::~BoxClicker()
{
    delete this->postGameMenu;
}

//Accessors
const bool BoxClicker::getEndGame() const
{
    return this->endGame;
}

const unsigned BoxClicker::getScore() const
{
    return this->points;
}

const bool BoxClicker::getAddingScore() const
{
    return this->postGameMenu->getAddingScore();
}

bool BoxClicker::isPostGameNull()
{
    if (this->postGameMenu == NULL)
    {
        return true;
    }

    else
    {
        return false;
    }
}

//MODIFIERS

void BoxClicker::setString(char character)
{
    this->postGameMenu->setString(character);
}

void BoxClicker::setAddingScore(bool isAddingScore)
{
    this->postGameMenu->setAddingScore(isAddingScore);
}


//Functions
void BoxClicker::spawnEnemy()
{
    /*
        @return void

        Spawns enemies and sets their types, colours. Spawn them in positions randomly.
        -Sets a random type (diff)
        -Sets a random position.
        =Sets a random colour.
        -Adds enemy to the vector.
    */

    //Set random position
    this->enemy.setPosition(static_cast<float>(rand() % static_cast<int>(this->screenBounds.width - this->enemy.getSize().x)), 0.f);

    //Randomize enemy type
    int type = rand() % 4;

    switch (type)
    {
    case 0:
        this->enemy.setSize(sf::Vector2f(30.f, 30.f));
        this->enemy.setFillColor(sf::Color::Magenta);
        break;
    case 1:
        this->enemy.setSize(sf::Vector2f(60.f, 60.f));
        this->enemy.setFillColor(sf::Color::Blue);
        break;
    case 2:
        this->enemy.setSize(sf::Vector2f(80.f, 80.f));
        this->enemy.setFillColor(sf::Color::Cyan);
        break;
    case 3:
        this->enemy.setSize(sf::Vector2f(100.f, 100.f));
        this->enemy.setFillColor(sf::Color::Red);
        break;
    case 4:
        this->enemy.setSize(sf::Vector2f(125.f, 125.f));
        this->enemy.setFillColor(sf::Color::Green);
        break;
    default:
        this->enemy.setSize(sf::Vector2f(150.f, 150.f));
        this->enemy.setFillColor(sf::Color::Yellow);
        break;
    }

    //Spawn the enemy
    this->enemies.push_back(this->enemy);

    //Remove enemies at end of screen
}


void BoxClicker::updateMousePositions(sf::Vector2f mousePos)
{
    /*
        @return void

        Updates the mouse positions:
         - Mouse position relative to window (Vector2i)

    */
    
    this->mousePosView = mousePos;
}

//Functions
void BoxClicker::update(sf::Vector2f mousePos)
{

    if (this->isPostGame == false)
    {
        this->updateMousePositions(mousePos);
        this->updateText();
        this->updateEnemies();
    }

    else
    {
        switch (this->postGameMenu->getUserSelection())
        {
            //Nothing selected
        case 0:
            this->postGameMenu->update(mousePos);
            this->postGameMenu->menuInteraction(mousePos);
            break;

            //Play again selected
        case 1:
            this->restartGame();
            break;

            //Add score selected
        case 2:
            std::cout << "Add score selected" << std::endl;
            break;

            //Quit selected
        case 3:
            this->endGame = true;
            break;
        }

        
        

    }

    //End BoxClicker condition
    if (this->health <= 0 && this->isPostGame == false)
    {
        //Open post game menu
        this->postGameMenu = new PostGameMenu(this->font, this->screenBounds);
        this->isPostGame = true;
    }

}

void BoxClicker::updateText()
{
    std::stringstream ss;

    ss << "Points: " << this->points << std::endl << "Health: " << this->health << std::endl;

    this->uiText.setString(ss.str());
}

void BoxClicker::updateEnemies()
{
    /*
        @return void

        -Update the enemy spawn timer and spawns enemies when the total amount of enemies is smaller than the max.
        -Moves the enemies downwards.
        -Removes the enemies at the edge of the screen.
    */

    //Updating the timer for enemy spawning
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            //Spawn the enemy and reset the timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
        {
            this->enemySpawnTimer += 1.f;
        }
    }

    //Move and updating the enemies
    for (int i = 0; i < this->enemies.size(); i++)
    {
        bool deleted = false;

        this->enemies[i].move(0.f, 3.f);

        //If the enemy is past the bottom of the screen
        if (this->enemies[i].getPosition().y > this->screenBounds.height)
        {
            this->enemies.erase(this->enemies.begin() + i);
            this->health -= 1;
        }

    }

    //Check if clicked upon
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (this->mouseHeld == false)
        {
            this->mouseHeld = true;
            bool deleted = false;
            for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
            {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
                {

                    //Gain points
                    if (this->enemies[i].getFillColor() == sf::Color::Magenta)
                    {
                        this->points += 10;
                    }

                    else if (this->enemies[i].getFillColor() == sf::Color::Blue)
                    {
                        this->points += 7;
                    }

                    else if (this->enemies[i].getFillColor() == sf::Color::Cyan)
                    {
                        this->points += 5;
                    }

                    else if (this->enemies[i].getFillColor() == sf::Color::Red)
                    {
                        this->points += 3;
                    }

                    else if (this->enemies[i].getFillColor() == sf::Color::Green)
                    {
                        this->points += 1;
                    }

                    //Delete the enemy
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);

                }

            }

        }

    }

    else
    {
        this->mouseHeld = false;
    }

}

void BoxClicker::render(sf::RenderTarget& target)
{
    target.clear();
    this->renderEnemies(target);
    this->renderText(target);

    if (this->isPostGame)
    {
        //Render post game screen
        this->postGameMenu->render(target);

    }

}

void BoxClicker::renderText(sf::RenderTarget& target)
{
    target.draw(this->uiText);
}

void BoxClicker::renderEnemies(sf::RenderTarget& target)
{
    //Rendering all the enemies.
    for (auto& em : this->enemies)
    {
        target.draw(em);
    }
}
