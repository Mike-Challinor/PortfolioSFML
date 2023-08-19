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

BaseGameThumbnails::BaseGameThumbnails()
{
	this->spriteTexture = new sf::Texture();
	this->sprite = new sf::Sprite();
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

void BaseGameThumbnails::update()
{
	if (this->isEnlarging || this->isShrinking)
	{
		this->updateSpriteSize();
		this->highlightBox.setSize(sf::Vector2f(this->sprite->getGlobalBounds().width + 10.f, this->sprite->getGlobalBounds().height + 10.f));
	}
}

void BaseGameThumbnails::render(sf::RenderTarget& target)
{
	target.draw(this->highlightBox);
	target.draw(*this->sprite);
}
