#include "MainMenu.h"


int main()
{

	//Init random seed
	srand(static_cast<unsigned>(time(NULL)));

	/*int currentGameState = 0;
	enum gameStates {MAINMENU = 0, BOXCLICKER = 1};*/

	//Init Game State
	GameState gameState;

	//Init main menu
	MainMenu mainMenu(gameState);

	//Application Loop
	while (mainMenu.applicationRunning())
	{
		std::cout << "Game State = " << gameState.getCurrentGameState() << std::endl;

		mainMenu.updateMousePosition();

		switch (gameState.getCurrentGameState())
		{
		case gameState.MAINMENU:

			mainMenu.pollEvents();

			//Main Menu running
			mainMenu.update();
			mainMenu.render();

			break;

		case gameState.BOXCLICKER:

			mainMenu.pollEvents();

			//Box clicker running
			mainMenu.updateBoxClicker();
			mainMenu.renderBoxClicker();
			mainMenu.displayRender();

			break;
		}
		
	}

	std::cout << "Ending application";

	//End of application
	return 0;

}