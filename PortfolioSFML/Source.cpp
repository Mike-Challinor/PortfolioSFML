#include "MainMenu.h"
#include "BoxClicker.h"


int main()
{
	//Init random seed
	srand(static_cast<unsigned>(time(NULL)));

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

	std::cout << "Ending application";

	//End of application
	return 0;

}