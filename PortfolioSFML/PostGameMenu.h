#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Textfield.h"

class PostGameMenu
{
private:

	//VIDEO MODE
	sf::VideoMode screenBounds;

	//CLASSES
	Textfield* textField;

	//COLOURS
	sf::Color buttonColour;
	sf::Color buttonHighlightedColour;

	//FONTS
	sf::Font font;

	//SHAPES
	sf::RectangleShape menuPanel;
	sf::RectangleShape playButton;
	sf::RectangleShape enterScoreButton;
	sf::RectangleShape exitButton;

	//TEXT
	sf::Text menuTitleText;
	sf::Text playButtonText;
	sf::Text scoreButtonText;
	sf::Text exitButtonText;

	//BOOLS
	bool menuOpen;
	bool mouseHeld;
	bool addingScore;
	bool scoreEntered;

	//INTS
	int userSelection;
	int gameNum;

	//PRIVATE FUNCTIONS
	void initVar(sf::VideoMode screen_bounds, int game_num);
	void initFont(sf::Font font);
	void initGUI();
	void initButtons();
	void initText();


public:

	//CONSTRUCTORS AND DESTRUCTORS
	PostGameMenu(sf::Font font, sf::VideoMode screen_bounds, int game_num);
	~PostGameMenu();

	//PUBLIC FUNCTIONS
	void menuInteraction(sf::Vector2f mouse_pos);
	void removeChar();
	void closeMenu();

	//ACCESSORS
	const bool getMenuOpen() const;
	const int getUserSelection() const;
	const bool getAddingScore() const;
	const bool textFieldInFocus() const;
	const bool getScoreEntered() const;
	const std::string getName() const;

	//MODIFIERS
	void setMenuOpen(bool is_open);
	void addChar(char character);
	void setAddingScore(bool isAddingScore);
	void setTextFieldFocus(bool in_focus);
	void setScoreEntered(bool score_entered);

	//UPDATES
	void update(sf::Vector2f mouse_pos);
	void updateGUI(sf::Vector2f mouse_pos);

	//RENDERS
	void render(sf::RenderTarget& target);
	void renderGUI(sf::RenderTarget& target);
	void renderPanels(sf::RenderTarget& target);
	void renderButtons(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);



};

