#include <SFML/Graphics.hpp>
#include"myButton.h"
using namespace minh;


int main()
{
    sf::RenderWindow favWindow(sf::VideoMode(1600, 900), "Favourite List", sf::Style::Close);
    sf::RectangleShape Background(sf::Vector2f(1600.0f, 900.0f));
    Background.setFillColor(sf::Color::Blue);

    sf::RectangleShape title(sf::Vector2f(800.0f, 100.0f));
    title.setOutlineThickness(2.0f);
    title.setOutlineColor(sf::Color::Black);
    title.setOrigin(400.0f, 50.0f);
    title.setPosition(800.0f, 80.0f);
    title.setFillColor(sf::Color::White);


    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text textTitle;
    textTitle.setFont(font);
    textTitle.setCharacterSize(50);
    textTitle.setFillColor(sf::Color::Black);
    textTitle.setPosition(610.0f, 50.0f);
    textTitle.setString("FAVOURITE LIST");

    minh::button ViewButton, AddButton, DeleteButton;

    ViewButton.setButton(sf::Vector2f(266.0f,50.0f), 400.0f, 135.0f, sf::Color::White, 2.0f, sf::Color::Black);
    ViewButton.setTextButton(490.0f, 135.0f, font, 40, "VIEW", sf::Color::Black);

    AddButton.setButton(sf::Vector2f(266.0f, 50.0f), 668.0f, 135.0f, sf::Color::White, 2.0f, sf::Color::Black);
    AddButton.setTextButton(760.0f, 135.0f, font, 40, "ADD", sf::Color::Black);

    DeleteButton.setButton(sf::Vector2f(266.0f, 50.0f), 934.0f, 135.0f, sf::Color::White, 2.0f, sf::Color::Black);
    DeleteButton.setTextButton(990.0f, 135.0f, font, 40, "DELETE", sf::Color::Black);

    while (favWindow.isOpen())
    {

        sf::Event evnt;
        while (favWindow.pollEvent(evnt))
        {
            switch (evnt.type)
            {
                case sf::Event::Closed:
                    favWindow.close();
                    break;
                
            }
        }


        ViewButton.touchingButton(favWindow);
        AddButton.touchingButton(favWindow);
        DeleteButton.touchingButton(favWindow);

        favWindow.clear();
        favWindow.draw(Background);
        favWindow.draw(title);
        favWindow.draw(textTitle);
        AddButton.draw(favWindow);
        ViewButton.draw(favWindow);
        DeleteButton.draw(favWindow);
        favWindow.display();
    }
}