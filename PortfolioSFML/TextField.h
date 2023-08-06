#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class TextField : public sf::Transformable, public sf::Drawable
{
public:
    TextField(unsigned int maxChars) :
        m_size(maxChars),
        m_rect(sf::Vector2f(15 * m_size, 20)), // 15 pixels per char, 20 pixels height, you can tweak
        m_hasfocus(false)
    {
        m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf"); // I'm working on Windows, you can put your own font instead
        m_rect.setOutlineThickness(2);
        m_rect.setFillColor(sf::Color::White);
        m_rect.setOutlineColor(sf::Color(127, 127, 127));
        m_rect.setPosition(this->getPosition());
    }

    const std::string getText() const;

    void setPosition(float x, float y);

    bool contains(sf::Vector2f point) const;

    void setFocus(bool focus);

    void handleInput(sf::Event e);

private:
    unsigned int m_size;
    sf::Font m_font;
    std::string m_text;
    sf::RectangleShape m_rect;
    bool m_hasfocus;

    
};

