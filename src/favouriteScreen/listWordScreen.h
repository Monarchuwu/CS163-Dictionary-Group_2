#pragma once
#include <SFML/Graphics.hpp>
#include"myButton.h"
#include "myBox.h"
#include <iostream>
#include "fileWork.h"
#include "../Constant.h"
#include "../Screen.h"

namespace minh {
    class ScreenListWord : public Screen {
    public:
        ScreenListWord();

        void setListWord(const std::vector<std::string>& listWord);

        // Event Handle
        void handleEvent(const sf::Event& evnt) override;

        // Update
        void update() override;

        // Render - Draw
        void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

    private:
        std::vector<std::string> listWord;

        // OBJECT ON THE SCREEN
        int page    = 0;
        bool isView = 0;
        sf::RectangleShape Background;
        sf::RectangleShape subBackground1;
        sf::RectangleShape subBackground2;
        sf::Color backgroundColor;
        sf::RectangleShape title;
        sf::Text textTitle;
        sf::Text HeadWord;
        button ViewButton; //, AddButton, DeleteButton;
        button getBack;
        sf::Texture leftArrow;
        Box DefBox;
        // Box AddBox, DefBox;
        std::string text_input, def_input;
        sf::Text view[11];
    }; // namespace minh
} // namespace minh
