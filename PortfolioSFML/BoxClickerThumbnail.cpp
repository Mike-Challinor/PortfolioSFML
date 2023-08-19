#include "BoxClickerThumbnail.h"

void BoxClickerThumbnail::initTexture()
{
	if (!this->spriteTexture->loadFromFile("Resources/Textures/boxClickerThumbnail.png"))
	{
		std::cout << "ERROR::GAMESMENU::INITBUTTONS:: Failed to load boxClickerThumbnail.png" << std::endl;
	}
}
