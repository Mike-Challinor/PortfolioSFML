#include "SwagBallGame.h"

void SwagBallGame::initGameVars()
{
	this->gameNum = 2;
	this->hasScores = true;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 10;
	this->points = 0;
	this->swagBalls.clear();
}

void SwagBallGame::initText()
{
	//GUI Text init
	this->guiText.setFont(this->font);
	this->guiText.setCharacterSize(32);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setString("TEMP");
}

void SwagBallGame::restartGame()
{
	this->isPostGame = false;
	this->addingScore = false;

	//Ball Swag Logic
	this->spawnTimer = this->spawnTimerMax;
	this->points = 0;
	this->swagBalls.clear();
}

//Constructors and Destructors
SwagBallGame::SwagBallGame()
{

}

SwagBallGame::~SwagBallGame()
{

}

const int SwagBallGame::randBallType() const
{
	int type = swagBallTypes::DEFAULT;
	int randValue = rand() % 100 + 1;

	if (randValue > 60 && randValue <= 80)
	{
		type = swagBallTypes::DAMAGING;
	}

	else if (randValue > 80 && randValue <= 100)
	{
		type = swagBallTypes::HEALING;
	}

	return type;
}

void SwagBallGame::spawnSwagBalls()
{
	//Timer
	if (this->spawnTimer < this->spawnTimerMax)
	{
		this->spawnTimer += 1.f;
	}

	else
	{
		if (this->swagBalls.size() < this->maxSwagBalls)
		{
			this->swagBalls.push_back(SwagBall(this->screenBounds, this->randBallType()));
			this->spawnTimer = 0.f;
		}
	}
}

void SwagBallGame::updateCollision()
{
	//Check the collision
	for (size_t i = 0; i < this->swagBalls.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
		{
			switch (this->swagBalls[i].getType())
			{
			case swagBallTypes::DEFAULT:
				
				//Add points
				this->points++;
				break;

			case swagBallTypes::DAMAGING:
				
				//Damage player
				this->player.takeDamage(1);
				break;

			case swagBallTypes::HEALING:
				
				//Heal player
				this->player.gainHealth(1);
				break;

			}

			

			//Remove the ball
			this->swagBalls.erase(this->swagBalls.begin() + i);
		}
	}

	
}

void SwagBallGame::updateGUI()
{
	std::stringstream ss;
	ss << "Points: " << this->points << "\n" << "Health: " << this->player.getHp() << " / " << this->player.getHpMax();
	this->guiText.setString(ss.str());
}

void SwagBallGame::updatePlayer(sf::VideoMode screen_bounds)
{
	this->player.update(screen_bounds);

	if (this->player.getHp() <= 0)
	{
		this->callPostGame();
	}
}

void SwagBallGame::update()
{
	if (this->endGame == false)
	{
		this->spawnSwagBalls();
		this->updatePlayer(this->screenBounds);
		this->updateCollision();
		this->updateGUI();
	}

}

void SwagBallGame::renderGUI(sf::RenderTarget& target)
{
	target.draw(this->guiText);
}

void SwagBallGame::render(sf::RenderTarget& target)
{
	//Render player
	this->player.render(target);

	//Render Swagballs
	for (auto i : this->swagBalls)
	{
		i.render(target);
	}

	//Render GUI
	this->renderGUI(target);

}


