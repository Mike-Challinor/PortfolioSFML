#include "MainMenu.h"


int main()
{
	//Init random seed
	srand(static_cast<unsigned>(time(0)));

	//Init main menu
	MainMenu mainMenu;

	//Application Loop
	while (mainMenu.applicationRunning())
	{
		while (mainMenu.mainMenuRunning())
		{
			//Main Menu running
			mainMenu.update();
			mainMenu.render();
		}
	}

	//End of application
	return 0;

}