#pragma once

#include "BaseGame.h"
#include "SwagBallPlayer.h"
#include "SwagBall.h"

class SwagBallGame : public BaseGame
{
private:
	//Variables

	//Text
	sf::Text guiText;

	//Classes
	SwagBallPlayer player;

	//Vectors
	std::vector<SwagBall> swagBalls;

	//Floats
	float spawnTimerMax;
	float spawnTimer;

	//Ints
	int maxSwagBalls;

	//Init Functions
	void initGameVars() override;
	void initText() override;

	void restartGame() override;

public:
	//Constructors and Destructors
	SwagBallGame();
	~SwagBallGame();

	//Modifiers

	//Functions
	const int randBallType() const;

	//Spawns
	void spawnSwagBalls();

	//Updates
	void updateCollision();
	void updateGUI();
	void updatePlayer(sf::VideoMode screen_bounds);
	void update() override;

	//Renders
	void renderGUI(sf::RenderTarget& target);
	void render(sf::RenderTarget& target) override;
};

