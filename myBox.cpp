#include "myBox.h"
#include <iostream>
namespace minh
{

    void Box::setTextBox(sf::Vector2f buttonSize, float x, float y, sf::Color colorInside, float outlineThick, sf::Color colorOutline)
    {
        boxRec.setSize(buttonSize);
        boxRec.setFillColor(colorInside);
        boxRec.setPosition(x, y);
        boxRec.setOutlineThickness(outlineThick);
        boxRec.setOutlineColor(colorOutline);
    }

    bool Box::isTouching(sf::RenderWindow &window) {
        sf::Vector2i mousePos     = sf::Mouse::getPosition(window);
        sf::FloatRect buttonBound = boxRec.getGlobalBounds();
        bool isOntheButton        = buttonBound.contains(sf::Vector2f(mousePos));
        if (isOntheButton) return true;
        else return false;
    }

    void Box::setText(float x, float y, sf::Font &font, int sizeChar, sf::String str, sf::Color fillColor) {
        boxText.setFont(font);
        boxText.setCharacterSize(sizeChar);
        boxText.setFillColor(fillColor);
        boxText.setPosition(x, y);
        boxText.setString(str);
    }

    void Box::writing( sf::Event evnt, std::string &text_input) {

        if (evnt.text.unicode < 128 && writeThis == true && evnt.text.unicode != '\r') {
            if (evnt.text.unicode == 8) {
                if (!text_input.empty()) {
                    text_input.erase(text_input.size() - 1);
                }
            }
            else {
                text_input += evnt.text.unicode;
            }
        }
        boxText.setString(text_input);
        boxText.setFillColor(sf::Color::Black);
        if (evnt.text.unicode == '\r' && !text_input.empty()) {
            std::cout << "Enter: " << text_input << std::endl;
            //text_input = "";
            writeThis = false;
        }
    }

    void Box::draw(sf::RenderWindow& window)
    {
        window.draw(boxRec);
        window.draw(boxText);
    }
    
}