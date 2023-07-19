#pragma once
#include <SFML/Graphics.hpp>
#include"myButton.h"
#include "myBox.h"
#include <iostream>
#include "fileWork.h"
namespace minh {

    class ScreenFavou {

    
    public:
        ScreenFavou();
        void run();

    private:
        //OBJECT ON THE SCREEN
        sf::RenderWindow favWindow;
        sf::RectangleShape Background;
        sf::Color backgroundColor;
        sf::RectangleShape title;
        sf::Font font;
        sf::Text textTitle;
        sf::Text HeadWord;
        button ViewButton, AddButton, DeleteButton;
        int option;
        Box AddBox, DefBox;
        std::string text_input, def_input, headword_input;
        sf::Text view[10];
        sf::Event evnt;
        //Event Handle
        void handleEvent(const sf::Event& evnt);

        //Update
        void update();

        //Render - Draw 
        void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

	};
} // namespace minh