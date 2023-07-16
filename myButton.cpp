#include <SFML/Graphics.hpp>
#include"myButton.h"

namespace minh{

    bool button::isTouching(sf::RenderWindow &window)
    {
        sf::Vector2i mousePos     = sf::Mouse::getPosition(window);
        sf::FloatRect buttonBound = buttonRec.getGlobalBounds();
        bool isOntheButton        = buttonBound.contains(sf::Vector2f(mousePos));
        if (isOntheButton) return true;
        else return false;
    }

    void button::setButton(sf::Vector2f buttonSize , float x, float y, sf::Color colorInside, float outlineThick, sf::Color colorOutline) {
        buttonRec.setSize(buttonSize);
        buttonRec.setFillColor(colorInside);
        buttonRec.setPosition(x, y);
        buttonRec.setOutlineThickness(outlineThick);
        buttonRec.setOutlineColor(colorOutline);
    }

    void button::setTextButton(float x, float y, sf::Font &font, int sizeChar, sf::String str, sf::Color fillColor) {
        buttonText.setFont(font);
        buttonText.setCharacterSize(sizeChar);
        buttonText.setFillColor(fillColor);
        buttonText.setPosition(x, y);
        buttonText.setString(str);
    }

    void button::touchingButton(sf::RenderWindow &window) {
        sf::Vector2i mousePos     = sf::Mouse::getPosition(window);
        sf::FloatRect buttonBound = buttonRec.getGlobalBounds();
        bool isOntheButton        = buttonBound.contains(sf::Vector2f(mousePos));
        if (isOntheButton) {
            buttonText.setFillColor(sf::Color::Red);
        }
        else buttonText.setFillColor(sf::Color::Black);
    }

    void button::draw(sf::RenderWindow &window) {
        window.draw(buttonRec);
        window.draw(buttonText);
    }
    

}
