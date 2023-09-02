#include "BaseGameThumbnails.h"

void BaseGameThumbnails::initTexture(std::string file_path)
{
	if (!this->spriteTexture->loadFromFile(file_path))
	{
		std::cout << "ERROR::BASEGAMETHUMBNAILS::INITTEXTURE:: Failed to load texture" << std::endl;
	}
}

void BaseGameThumbnails::initSprite()
{

	if (this->spriteTexture != nullptr)
	{
		if (this->sprite != nullptr)
		{
			//Init sprite
			this->sprite->setTexture(*this->spriteTexture);
			this->sprite->setTextureRect(this->deselectedRect);
			this->sprite->setScale(0.35f, 0.35f);

			//Set button colours
			this->buttonColour = sf::Color(177, 177, 177, 177);

			//Init sprite button background
			this->highlightBox.setFillColor(this->buttonColour);
			this->highlightBox.setSize(sf::Vector2f(this->sprite->getGlobalBounds().width + 10.f, this->sprite->getGlobalBounds().height + 10.f));

		}

		else
		{
			std::cout << "ERROR::BASEGAMETHUMBNAILS::INITSPRITE:: Sprite returning null ptr" << std::endl;
		}
		
	}

	else
	{
		std::cout << "ERROR::BASEGAMETHUMBNAILS::INITSPRITE:: Sprite texture returning null ptr" << std::endl;
	}
}

void BaseGameThumbnails::initText(sf::Font font, std::string title_string, std::string description_text)
{
	//Set font
	this->font = font;

	//Init title text
	this->titleText.setFont(this->font);
	this->titleText.setCharacterSize(24);
	this->titleText.setFillColor(sf::Color(177, 177, 177));
	this->titleText.setOutlineThickness(1.f);
	this->titleText.setOutlineColor(sf::Color::Black);
	this->titleText.setString(title_string);
	this->titleText.setPosition(this->highlightBox.getGlobalBounds().left + this->highlightBox.getGlobalBounds().width / 2 - this->titleText.getGlobalBounds().width / 2, this->highlightBox.getGlobalBounds().top - this->titleText.getGlobalBounds().height / 2 - 5.f);

	//Init description box
	this->descriptionBoxColour = sf::Color(177, 177, 177, 0);
	this->descriptionBoxHighlightColour = sf::Color(177, 177, 177, 155);
	this->descriptionBox.setFillColor(this->descriptionBoxColour);
	this->descriptionBox.setPosition(this->highlightBox.getGlobalBounds().left, this->highlightBox.getGlobalBounds().top + this->highlightBox.getGlobalBounds().height);
	this->descriptionBox.setSize(sf::Vector2f(this->highlightBox.getGlobalBounds().width, 100.f));

	//Init description text

	//Init colours
	this->descriptionTextColour = sf::Color(255, 255, 255, 0);					//White transparent
	this->descriptionHighlightedTextColour = sf::Color(255, 255, 255, 255);		//White semi-transparent
	this->outlineTextColour = sf::Color(0, 0, 0, 0);							//Black transparent
	this->outlineTextColourHighlighted = sf::Color(0, 0, 0, 255);				//Black opaque

	this->descriptionText.setFont(this->font);
	this->descriptionText.setCharacterSize(18);
	this->descriptionText.setFillColor(this->descriptionTextColour);
	this->descriptionText.setOutlineThickness(0.3f);
	this->descriptionText.setOutlineColor(sf::Color::Black);
	this->descriptionText.setString(description_text);
	this->descriptionText.setPosition(this->descriptionBox.getGlobalBounds().left + 5.f, this->descriptionBox.getGlobalBounds().top + 5.f);
}

BaseGameThumbnails::BaseGameThumbnails()
{
	this->spriteTexture = new sf::Texture();
	this->sprite = new sf::Sprite();
	this->isHighlighted = false;
	this->descriptionBoxFadeTimer.restart();
	this->isTextFading = false;
	this->fadeInSpeed = 50.f;
	this->fadeOutSpeed = 150.f;
}

BaseGameThumbnails::~BaseGameThumbnails()
{
	delete this->spriteTexture;
	delete this->sprite;
}

void BaseGameThumbnails::updateSpriteSize()
{
	int temp_width = this->sprite->getTextureRect().width;
	int temp_left = this->sprite->getTextureRect().left;

	if (this->enlargingTimer.getElapsedTime().asMilliseconds() >= 3.75f)
	{
		if (this->isEnlarging)
		{
			if(this->sprite->getTextureRect().width < selectedRect.width || this->sprite->getTextureRect().left > this->selectedRect.left)
			{
				if (temp_width != this->selectedRect.width)
				{
					temp_width += 10;
					this->enlargingTimer.restart();
				}
				if (temp_left != this->selectedRect.left)
				{
					temp_left -= 5;
					this->enlargingTimer.restart();
				}
			}

			else if (this->sprite->getTextureRect() == this->selectedRect)
			{
				this->isEnlarging = false;
			}
		}
			
		else if (this->isShrinking)
		{
			if (this->sprite->getTextureRect().width > this->deselectedRect.width && this->sprite->getTextureRect().left < this->deselectedRect.left)
			{
				if (temp_width != this->deselectedRect.width)
				{
					temp_width -= 10;
				}
				if (temp_left != this->deselectedRect.left)
				{
					temp_left += 5;
				}
			}

			else if (this->sprite->getTextureRect() == this->deselectedRect)
			{
				this->isShrinking = false;
			}

		}

		this->sprite->setTextureRect(sf::IntRect(temp_left, 0, temp_width, 600));

		this->enlargingTimer.restart();
	}
}

const sf::Sprite BaseGameThumbnails::getSprite() const
{
	return *this->sprite;
}

const bool BaseGameThumbnails::getIsEnlarging() const
{
	return this->isEnlarging;
}

const bool BaseGameThumbnails::getIsShrinking() const
{
	return this->isShrinking;
}

const sf::Color BaseGameThumbnails::getHighlightColour() const
{
	return this->highlightBox.getFillColor();
}

const sf::RectangleShape BaseGameThumbnails::getHighlightBox() const
{
	return this->highlightBox;
}

void BaseGameThumbnails::setPosition(float pos_x, float pos_y)
{
	this->sprite->setPosition(pos_x, pos_y);
	this->highlightBox.setPosition(this->sprite->getGlobalBounds().left - 5.f, this->sprite->getGlobalBounds().top - 5.f);
}

void BaseGameThumbnails::setIsEnlarging(bool is_enlarging)
{
	this->isEnlarging = is_enlarging;
}

void BaseGameThumbnails::setIsShrinking(bool is_shrinking)
{
	this->isShrinking = is_shrinking;
}

void BaseGameThumbnails::setHighlightColour(sf::Color color)
{
	this->highlightBox.setFillColor(color);
}

void BaseGameThumbnails::setTextColour(sf::Color color)
{
	this->titleText.setFillColor(color);
}

void BaseGameThumbnails::setisHighlighted(bool is_highlighted)
{
	if (this->isHighlighted != is_highlighted)
	{
		this->descriptionBoxFadeTimer.restart();
	}

	this->isHighlighted = is_highlighted;
}

void BaseGameThumbnails::update()
{
	this->updateGUI();

	if (this->isEnlarging || this->isShrinking)
	{
		this->updateSpriteSize();
		this->highlightBox.setSize(sf::Vector2f(this->sprite->getGlobalBounds().width + 10.f, this->sprite->getGlobalBounds().height + 10.f));
	}
}

void BaseGameThumbnails::updateGUI()
{
	this->updateShapes();
	this->updateText();
}

void BaseGameThumbnails::updateText()
{
	//Set title texts position
	this->titleText.setPosition(this->highlightBox.getGlobalBounds().left + this->highlightBox.getGlobalBounds().width / 2 - this->titleText.getGlobalBounds().width / 2, this->highlightBox.getGlobalBounds().top - this->titleText.getGlobalBounds().height / 2 - 5.f);

	if (this->isTextFading)
	{
		//Change to alpha
		sf::Time elapsed = this->descriptionBoxFadeTimer.getElapsedTime();
		float alpha_change_in_float = this->fadeInSpeed * elapsed.asSeconds();
		float alpha_change_out_float = this->fadeOutSpeed * elapsed.asSeconds();
		int alpha_change_in = static_cast<int>(alpha_change_in_float);
		int alpha_change_out = static_cast<int>(alpha_change_out_float);

		//Fade in
		if (this->isHighlighted)
		{
			//Adjusting text alpha
			if (this->descriptionText.getFillColor().a < this->descriptionHighlightedTextColour.a)
			{
				int new_alpha = (this->descriptionText.getFillColor().a + alpha_change_in < this->descriptionHighlightedTextColour.a) ? this->descriptionText.getFillColor().a + alpha_change_in : this->descriptionHighlightedTextColour.a;
				this->descriptionText.setFillColor(sf::Color(this->descriptionText.getFillColor().r, this->descriptionText.getFillColor().g, this->descriptionText.getFillColor().b, new_alpha));
			}

			//Adjusting outline alpha
			if (this->descriptionText.getOutlineColor().a < this->outlineTextColourHighlighted.a)
			{
				int new_alpha = this->descriptionText.getOutlineColor().a + alpha_change_in;

				if (new_alpha > this->outlineTextColourHighlighted.a)
				{
					new_alpha = this->outlineTextColourHighlighted.a;
				}

				this->descriptionText.setOutlineColor(sf::Color(this->descriptionText.getOutlineColor().r, this->descriptionText.getOutlineColor().g, this->descriptionText.getOutlineColor().b, new_alpha));
			}
		}

		//Fade out
		else
		{
			//Adjusting text alpha
			if (this->descriptionText.getFillColor().a > 0)
			{
				int new_alpha = (this->descriptionText.getFillColor().a - alpha_change_out > 0) ? this->descriptionText.getFillColor().a - alpha_change_out : 0;
				this->descriptionText.setFillColor(sf::Color(this->descriptionText.getFillColor().r, this->descriptionText.getFillColor().g, this->descriptionText.getFillColor().b, new_alpha));
			}

			//Adjusting outline alpha
			if (this->descriptionText.getOutlineColor().a > 0)
			{
				int new_alpha = this->descriptionText.getOutlineColor().a - alpha_change_out;
				if (new_alpha < 0)
				{
					new_alpha = 0;
				}

				this->descriptionText.setOutlineColor(sf::Color(this->descriptionText.getOutlineColor().r, this->descriptionText.getOutlineColor().g, this->descriptionText.getOutlineColor().b, new_alpha));
			}
		}

	}

	else
	{
		//Reset the text fading state when the description box is still resizing
		this->isTextFading = false;

		//Reset text fade timer
		this->descriptionTextFadeTimer.restart(); 
	
	}

	
}

void BaseGameThumbnails::updateShapes()
{
	//Update description box to size of the sprite (highlight box)
	this->descriptionBox.setPosition(this->highlightBox.getGlobalBounds().left, this->highlightBox.getGlobalBounds().top + this->highlightBox.getGlobalBounds().height);
	this->descriptionBox.setSize(sf::Vector2f(this->highlightBox.getGlobalBounds().width, 100.f));

	//Change to alpha
	sf::Time elapsed = this->descriptionBoxFadeTimer.getElapsedTime();
	float alpha_change_in_float = this->fadeInSpeed * elapsed.asSeconds();
	float alpha_change_out_float = this->fadeOutSpeed * elapsed.asSeconds();
	int alpha_change_in = static_cast<int>(alpha_change_in_float);
	int alpha_change_out = static_cast<int>(alpha_change_out_float);

	//Fade in
	if (this->isHighlighted)
	{
		if (this->descriptionBox.getFillColor().a < this->descriptionBoxHighlightColour.a)
		{
			int newAlpha = (this->descriptionBox.getFillColor().a + alpha_change_in < this->descriptionBoxHighlightColour.a) ? this->descriptionBox.getFillColor().a + alpha_change_in : this->descriptionBoxHighlightColour.a;
			this->descriptionBox.setFillColor(sf::Color(this->descriptionBox.getFillColor().r, this->descriptionBox.getFillColor().g, this->descriptionBox.getFillColor().b, newAlpha));
		}

		else
		{
			//Description box finished fading in
			this->isTextFading = true;
			this->descriptionTextFadeTimer.restart();
		}
	}

	//Fade out
	else
	{
		if (this->descriptionBox.getFillColor().a > 0)
		{
			int newAlpha = (this->descriptionBox.getFillColor().a - alpha_change_out > 0) ? this->descriptionBox.getFillColor().a - alpha_change_out : 0;
			this->descriptionBox.setFillColor(sf::Color(this->descriptionBox.getFillColor().r, this->descriptionBox.getFillColor().g, this->descriptionBox.getFillColor().b, newAlpha));
		}

		else
		{
			//Description box finished fading out
			this->isTextFading = true;
			this->descriptionTextFadeTimer.restart();
		}
	}

}

void BaseGameThumbnails::render(sf::RenderTarget& target)
{
	target.draw(this->highlightBox);
	target.draw(*this->sprite);
	target.draw(this->titleText);
	target.draw(this->descriptionBox);
	target.draw(this->descriptionText);
}
