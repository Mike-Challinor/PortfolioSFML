#include "MainMenu.h"


int main()
{
	//Init random seed
	srand(static_cast<unsigned>(time(NULL)));

	//Init Game State
	GameState gameState;

	//Init main menu
	MainMenu mainMenu(gameState);

	//Application Loop
	while (mainMenu.applicationRunning())
	{
		mainMenu.updateMousePosition();
		mainMenu.pollEvents();

		switch (gameState.getCurrentGameState())
		{
		case gameState.MAINMENU:

			//Main Menu running
			mainMenu.update();
			mainMenu.render();

			break;

		case gameState.GAME:

			//Box clicker running
			mainMenu.updateGame();
			mainMenu.renderGame();
			mainMenu.displayRender();

			break;
		}
		
	}

	std::cout << "Ending application";

	//End of application
	return 0;

}