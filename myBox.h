#pragma once
#include<SFML/Graphics.hpp>

namespace minh
{
    class Box {
    public:
        sf::RectangleShape boxRec;
        sf::Text boxText;

        bool writeThis = false;

        void setTextBox(sf::Vector2f BoxSize, float x, float y, sf::Color colorInside, float outlineThick, sf::Color colorOutline);

        void setText(float x, float y, sf::Font &font, int sizeChar, sf::String str, sf::Color fillColor);

        bool isTouching(sf::RenderWindow &window);
        
        void writing( sf::Event evnt, std::string& text_input);

        void draw(sf::RenderTarget &window) const;

        
    };
}

