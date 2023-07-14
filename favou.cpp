#include <SFML/Graphics.hpp>

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
    
    sf::RectangleShape ViewButton(sf::Vector2f(266.0f, 50.0f));
    ViewButton.setFillColor(sf::Color::White);
    ViewButton.setPosition(400.0f, 135.0f);
    ViewButton.setOutlineThickness(2.0f);
    ViewButton.setOutlineColor(sf::Color::Black);

    sf::RectangleShape AddButton(sf::Vector2f(266.0f, 50.0f));
    AddButton.setFillColor(sf::Color::White);
    AddButton.setPosition(668.0f, 135.0f);
    AddButton.setOutlineThickness(2.0f);
    AddButton.setOutlineColor(sf::Color::Black);

    sf::RectangleShape DeleteButton(sf::Vector2f(266.0f, 50.0f));
    DeleteButton.setFillColor(sf::Color::White);
    DeleteButton.setPosition(934.0f, 135.0f);
    DeleteButton.setOutlineThickness(2.0f);
    DeleteButton.setOutlineColor(sf::Color::Black);



    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text textTitle;
    textTitle.setFont(font);
    textTitle.setCharacterSize(50);
    textTitle.setFillColor(sf::Color::Black);
    textTitle.setPosition(610.0f, 50.0f);
    textTitle.setString("FAVOURITE LIST");

    sf::Text textAdd;
    textAdd.setFont(font);
    textAdd.setCharacterSize(40);
    textAdd.setFillColor(sf::Color::Black);
    textAdd.setPosition(760.0f, 135.0f);
    textAdd.setString("ADD");


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
        favWindow.clear();
        favWindow.draw(Background);
        favWindow.draw(title);
        favWindow.draw(ViewButton);
        favWindow.draw(AddButton);
        favWindow.draw(DeleteButton);
        favWindow.draw(textTitle);
        favWindow.draw(textAdd);
        favWindow.display();
    }
}