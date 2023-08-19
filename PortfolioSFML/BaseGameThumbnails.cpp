#include "BaseGameThumbnails.h"

void BaseGameThumbnails::initTexture()
{

}

void BaseGameThumbnails::initSprite()
{
	this->sprite->setTexture(*this->spriteTexture);
	this->sprite->setTextureRect(this->deselectedRect);
	this->sprite->setScale(0.35f, 0.35f);
}

BaseGameThumbnails::BaseGameThumbnails()
{
	this->initTexture();
	this->initSprite();
}

BaseGameThumbnails::~BaseGameThumbnails()
{

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
					temp_width += 5;
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
					temp_width -= 5;
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

void BaseGameThumbnails::setPosition(float pos_x, float pos_y)
{
	this->sprite->setPosition(pos_x, pos_y);
}

void BaseGameThumbnails::setIsEnlarging(bool is_enlarging)
{
	this->isEnlarging = is_enlarging;
}

void BaseGameThumbnails::setIsShrinking(bool is_shrinking)
{
	this->isShrinking = is_shrinking;
}

void BaseGameThumbnails::update()
{
	if (this->isEnlarging || this->isShrinking)
	{
		this->updateSpriteSize();
	}
}

void BaseGameThumbnails::render(sf::RenderTarget& target)
{
	target.draw(*this->sprite);
}
