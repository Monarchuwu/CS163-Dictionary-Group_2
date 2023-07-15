#pragma once
#include<SFML/Graphics.hpp>
namespace minh {
    class button {
    public:
        sf::RectangleShape buttonRec;
        sf::Text buttonText;

        void setButton(sf::Vector2f buttonSize, float x, float y, sf::Color colorInside, float outlineThick, sf::Color colorOutline);

        void setTextButton(float x, float y, sf::Font &font, int sizeChar, sf::String str, sf::Color fillColor);

        void touchingButton(sf::RenderWindow &window);

        void draw(sf::RenderWindow &windowP);
    };
} // namespace minh