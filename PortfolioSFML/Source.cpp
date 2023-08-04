#include "MainMenu.h"


int main()
{
	//Init random seed
	srand(static_cast<unsigned>(time(NULL)));

	//Init main menu
	MainMenu mainMenu;

	//Application Loop
	while (mainMenu.applicationRunning() && mainMenu.mainMenuRunning())
	{
		std::cout << "Application Running = " << mainMenu.applicationRunning() << std::endl;
		std::cout << "Main Menu Running = " << mainMenu.mainMenuRunning() << std::endl;

		//Main Menu running
		mainMenu.update();
		mainMenu.render();

	}

	std::cout << "Ending application";

	//End of application
	return 0;

}