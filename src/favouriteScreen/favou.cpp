#include <SFML/Graphics.hpp>
#include"myButton.h"
#include "myBox.h"
#include <iostream>
//#include "fileWork.h"
using namespace minh;


/* int main() {   
    //BASIC SCREEN SETUP
    sf::RenderWindow favWindow(sf::VideoMode(1600, 900), "Favourite List", sf::Style::Close);
    sf::RectangleShape Background(sf::Vector2f(1600.0f, 900.0f));
    sf::Color backgroundColor(102, 153, 255);
    Background.setFillColor(backgroundColor);

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

    sf::Text HeadWord;
    HeadWord.setFont(font);
    HeadWord.setCharacterSize(50);
    HeadWord.setFillColor(sf::Color::Transparent);
    HeadWord.setPosition(100.0f, 260.0f);
    HeadWord.setString("");


    minh::button ViewButton, AddButton, DeleteButton;// 3 MAIN FUNCTION BUTTON

    ViewButton.setButton(sf::Vector2f(266.0f, 50.0f), 400.0f, 135.0f, sf::Color::White, 2.0f, sf::Color::Black);
    ViewButton.setTextButton(490.0f, 135.0f, font, 40, "VIEW", sf::Color::Black);

    AddButton.setButton(sf::Vector2f(266.0f, 50.0f), 668.0f, 135.0f, sf::Color::White, 2.0f, sf::Color::Black);
    AddButton.setTextButton(760.0f, 135.0f, font, 40, "ADD", sf::Color::Black);

    DeleteButton.setButton(sf::Vector2f(266.0f, 50.0f), 934.0f, 135.0f, sf::Color::White, 2.0f, sf::Color::Black);
    DeleteButton.setTextButton(990.0f, 135.0f, font, 40, "DELETE", sf::Color::Black);

    int option = 0;// HANDLE 3 MAIN FUNCTION 

    minh::Box AddBox, DefBox;// BOX FOR USER INPUT AND OUTPUT (ADD BOX IS ALSO THE DELETE BOX)

    AddBox.setTextBox(sf::Vector2f(266.0f, 50.0f), 668.0f, 200.0f, sf::Color::Transparent, 2.0f, sf::Color::Transparent);
    AddBox.setText(680.0f, 205.0f, font, 30, "", sf::Color::Transparent);



    DefBox.setTextBox(sf::Vector2f(1400 ,620.0f),100.0f, 260.0f, sf::Color::White, 2.0f, sf::Color::Black);
    DefBox.setText(130.0f, 350.0f, font, 40, "", sf::Color::Transparent);

    std::string text_input, def_input, headword_input;


    sf::Text view[10];
    for (int i = 0; i < 10; i++)
    {
        view[i].setPosition(150.0f, 300.0f + i * 50.0f);
        view[i].setFillColor(sf::Color::Black);
        view[i].setFont(font);
    }
    while (favWindow.isOpen()) {
        sf::Event evnt;
        while (favWindow.pollEvent(evnt)) 
        {
            if (evnt.type == sf::Event::Closed)
                favWindow.close();

            else if (evnt.type == sf::Event::MouseButtonPressed) 
            {
                if (evnt.mouseButton.button == sf::Mouse::Left) {
                    if (AddButton.isTouching(favWindow)) {
                        std::cout << "Choosing add a new word" << std::endl;
                        AddBox.setTextBox(sf::Vector2f(266.0f, 50.0f), 668.0f, 200.0f, sf::Color::White, 2.0f, sf::Color::Black);
                        for (int i = 0; i < 10; i++)
                        {
                            view[i].setString("");
                        }
                        text_input = "";
                        def_input  = "";
                        HeadWord.setString("");
                        AddBox.boxText.setString(text_input); 
                        DefBox.boxText.setString(def_input);
                        AddBox.writeThis = true;
                        option           = 1;

                    }

                    else if (DeleteButton.isTouching(favWindow)) {
                        std::cout << "Choosing delete a word" << std::endl;
                        AddBox.setTextBox(sf::Vector2f(266.0f, 50.0f), 668.0f, 200.0f, sf::Color::White, 2.0f, sf::Color::Black);
                        text_input = "";
                        def_input  = "";
                        for (int i = 0; i < 10; i++) 
                        {
                            view[i].setString("");
                        }
                        HeadWord.setString("");
                        AddBox.boxText.setString(text_input);
                        DefBox.boxText.setString(def_input);
                        AddBox.writeThis = true;
                        option           = -1;
                    }

                    else if (ViewButton.isTouching(favWindow))
                    {
                        text_input = "";
                        def_input  = "";
                        headword_input = "";
                        HeadWord.setString("");
                        AddBox.boxText.setString(text_input);
                        DefBox.boxText.setString(def_input);

                        std::cout << "Choosing view words" << std::endl;
                        for (int i = 0; i < 10; i++)
                        {
                           std::string str = takeLine(i + 1, "data/favourite.txt");
                           for (int j = 0; j < str.size(); j++)
                           {
                               if (str[j] == ',')
                               {
                                   std::string word = str.substr(0, j);
                                   std::string def  = str.substr(j + 1);
                                   str              = word + " : " + def;
                                   //std::cout << str << std::endl;
                                   view[i].setString(str);
                                   break;
                               }
                           }
                        }
                    }
                }
            }

            if (evnt.type == sf::Event::TextEntered)
            {
                if (AddBox.writeThis && !DefBox.writeThis)  AddBox.writing(evnt, text_input);
                 if (AddBox.writeThis == false && DefBox.writeThis == false)
                {
                    sf::Color headColor(255, 80, 80);
                    HeadWord.setFillColor(headColor);
                    headword_input = "  " + text_input;
                    HeadWord.setString(headword_input);
                    DefBox.boxText.setFillColor(sf::Color::Black);
                    //def_input = "Definition goes at here";
                    if (option > 0)
                    {
                        std::cout << "Add to favourite list: " << text_input << std::endl;

                        //HANDLE BACK END ADD TO FAVOURITE LIST
                        std::string fileName = "data/Dictionary.txt";
                        def_input = defOfWord(text_input, fileName);
                        if (!def_input.size()) def_input = "ERROR: Can not find this word";
                        else
                        {
                            if (defOfWord(text_input, "data/favourite.txt") == "")// Not in the data/favourite.txt yet
                            addToEndOfFile(text_input, "data/favourite.txt", fileName);
                            else
                            {
                                def_input = "Already in the favourite list";
                            std::cout << "Word already in the favourite list" << std::endl;

                            }
                        }
                        option = 0;
                    }
                        
                    if (option < 0) 
                    {
                        std::cout << "Delete from favourite list: " << text_input << std::endl;
                       
                        //HANDLE BACK END DELETE FROM THE FAVOURITE LIST
                        std::string fileName = "data/Dictionary.txt";
                        def_input            = defOfWord(text_input, fileName);
                        if (!def_input.size()) def_input = "ERROR: Can not find this word";
                        else {
                            if (defOfWord(text_input, "data/favourite.txt") != "") // In the favourite already
                            clearFromFile(text_input, "data/favourite.txt");
                            else {
                            def_input = "Not in the favourite list";
                            std::cout << "Word not already in the favourite list" << std::endl;
                            }
                        }
                        option = 0;
                    }
                    
                    DefBox.boxText.setString(def_input);
                    option = 0;
                    //DefBox.writeThis = true; USE THIS IF WANT TO CHANGE DEFINITION
                }
                //DefBox.writing(evnt, def_input); USE THIS IF WANT TO CHANGE THE DEFINITION
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
        AddBox.draw(favWindow);
        DefBox.draw(favWindow);
        favWindow.draw(HeadWord);
        for (int i = 0; i < 10; i++)
        {
            favWindow.draw(view[i]);
        }
        favWindow.display();
    }
}
*/