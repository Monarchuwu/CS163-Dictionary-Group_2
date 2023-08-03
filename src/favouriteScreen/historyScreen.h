#pragma once
#include <SFML/Graphics.hpp>
#include"myButton.h"
#include "myBox.h"
#include <iostream>
#include "fileWork.h"
#include "../Constant.h"
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

        // Set type dictionary
        void changeDir(int dataset);

    private:
        // OBJECT ON THE SCREEN
        int page    = 0;
        bool isView = 0;
        sf::RenderWindow hisWindow;
        sf::RectangleShape Background;
        sf::RectangleShape subBackground1;
        sf::RectangleShape subBackground2;
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
        sf::Text view[11];
        sf::Event evnt;

    }; // namespace minh
} // namespace minh
