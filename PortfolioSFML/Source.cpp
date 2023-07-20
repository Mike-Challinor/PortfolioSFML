#include "MainMenu.h"
#include "BoxClicker.h"


int main()
{
	//Init random seed
	srand(static_cast<unsigned>(time(NULL)));

	//Init main menu
	MainMenu mainMenu;

	BoxClicker boxClicker;


	//Application Loop
	while (mainMenu.applicationRunning())
	{
		while (mainMenu.mainMenuRunning())
		{
			//Main Menu running
			mainMenu.update();
			mainMenu.render();		

		}


		if (mainMenu.boxClickerLaunched())
		{

			boxClicker.initGame(mainMenu.font, mainMenu.window);

			std::cout << boxClicker.getEndGame();

			while (!boxClicker.getEndGame())
			{
				std::cout << "Run Box Clicker" << std::endl;

				boxClicker.update(mainMenu.getMousePos());
				boxClicker.render(mainMenu.window);
			}


		}
	}

	std::cout << "Ending application";

	//End of application
	return 0;

}