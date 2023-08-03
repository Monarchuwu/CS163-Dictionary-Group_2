#pragma once
#include <SFML/Graphics.hpp>
#include"myButton.h"
#include "myBox.h"
#include <iostream>
#include "fileWork.h"
#include "../Screen.h"
#include "../Constant.h"
#include "../dataManager/DataManager.h" // include to use enum Dataset

namespace minh {

    class ScreenFavou : public Screen {

    
    public:
        //TrieWord Tree;
        std::string dic_type;

        ScreenFavou();

        void addAWord(std::string word);

        void deleteAWord(std::string word);

        bool inTheFile(std::string word);

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
        //OBJECT ON THE SCREEN
      
        sf::RenderWindow favWindow;
        sf::RectangleShape Background;
        sf::RectangleShape subBackground1;
        sf::RectangleShape subBackground2;
        sf::Color backgroundColor;
        sf::RectangleShape title;
        sf::Font font;
        sf::Text textTitle;
        sf::Text HeadWord;
        button ViewButton, AddButton, DeleteButton;
        button getBack;
        sf::Texture leftArrow;
        int option;
        int page;
        bool isView = 0;
        Box AddBox, DefBox;
        std::string text_input, def_input, headword_input;
        sf::Text view[11];
        sf::Event evnt;

	};
} // namespace minh