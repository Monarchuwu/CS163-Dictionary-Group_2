#pragma once
#include <SFML/Graphics.hpp>
#include"myButton.h"
#include "myBox.h"
#include <iostream>
#include "fileWork.h"
#include "../Screen.h"

namespace minh {
    class ScreenHis : public Screen {
    public:
        std::string dic_type;
        ScreenHis();
        void run();

        // Event Handle
        void handleEvent(const sf::Event& evnt) override;

        // Update
        void update() override;

        // Render - Draw
        void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

    private:
        // OBJECT ON THE SCREEN

        sf::RenderWindow hisWindow;
        sf::RectangleShape Background;
        sf::Color backgroundColor;
        sf::RectangleShape title;
        sf::Font font;
        sf::Text textTitle;
        sf::Text HeadWord;
        button ViewButton; //, AddButton, DeleteButton;
        button getBack;
        sf::Texture leftArrow;
        int option;
        Box DefBox;
        // Box AddBox, DefBox;
        std::string text_input, def_input;
        sf::Text view[10];
        sf::Event evnt;

    }; // namespace minh
} // namespace minh
