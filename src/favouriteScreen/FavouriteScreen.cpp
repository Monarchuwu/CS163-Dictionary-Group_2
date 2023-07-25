
#include "FavouriteScreen.h"
namespace minh
{
    ScreenFavou::ScreenFavou()
    {
        //Initialize Window
        //favWindow.create(sf::VideoMode(1600, 900), "Favourite List", sf::Style::Close);
        dic_type        = "slang";
        backgroundColor = sf::Color(102, 153, 255);
        Background.setSize(sf::Vector2f(1600.0f, 900.0f));
        Background.setFillColor(backgroundColor);
        //Setup font + object
        title.setSize(sf::Vector2f(800.0f, 100.0f));
        title.setOutlineThickness(2.0f);
        title.setOutlineColor(sf::Color::Black);
        title.setOrigin(400.0f, 50.0f);
        title.setPosition(800.0f, 80.0f);
        title.setFillColor(sf::Color::White);

        font.loadFromFile("arial.ttf");


        textTitle.setFont(font);
        textTitle.setCharacterSize(50);
        textTitle.setFillColor(sf::Color::Black);
        textTitle.setPosition(610.0f, 50.0f);
        textTitle.setString("FAVOURITE LIST");

        HeadWord.setFont(font);
        HeadWord.setCharacterSize(50);
        HeadWord.setFillColor(sf::Color::Transparent);
        HeadWord.setPosition(100.0f, 260.0f);
        HeadWord.setString("");

        option = 0;

        ViewButton.setButton(sf::Vector2f(266.0f, 50.0f), 400.0f, 135.0f, sf::Color::White, 2.0f, sf::Color::Black);
        ViewButton.setTextButton(490.0f, 135.0f, font, 40, "VIEW", sf::Color::Black);

        AddButton.setButton(sf::Vector2f(266.0f, 50.0f), 668.0f, 135.0f, sf::Color::White, 2.0f, sf::Color::Black);
        AddButton.setTextButton(760.0f, 135.0f, font, 40, "ADD", sf::Color::Black);

        DeleteButton.setButton(sf::Vector2f(266.0f, 50.0f), 934.0f, 135.0f, sf::Color::White, 2.0f, sf::Color::Black);
        DeleteButton.setTextButton(990.0f, 135.0f, font, 40, "DELETE", sf::Color::Black);

        getBack.buttonRec.setSize(sf::Vector2f(100.0f, 100.0f));
        getBack.buttonRec.setOutlineThickness(2.0f);
        getBack.buttonRec.setOutlineColor(sf::Color::Black);
        getBack.buttonRec.setPosition(1300.0f, 30.0f);
        leftArrow.loadFromFile("data/images/black_arrow.png");
        getBack.buttonRec.setTexture(&leftArrow);

       


        AddBox.setTextBox(sf::Vector2f(266.0f, 50.0f), 668.0f, 200.0f, sf::Color::Transparent, 2.0f, sf::Color::Transparent);
        AddBox.setText(680.0f, 205.0f, font, 30, "", sf::Color::Transparent);

        DefBox.setTextBox(sf::Vector2f(1400, 620.0f), 100.0f, 260.0f, sf::Color::White, 2.0f, sf::Color::Black);
        DefBox.setText(130.0f, 350.0f, font, 40, "", sf::Color::Transparent);

         for (int i = 0; i < 10; i++) {
            view[i].setPosition(150.0f, 300.0f + i * 50.0f);
            view[i].setFillColor(sf::Color::Black);
            view[i].setFont(font);
        }
    }

    void ScreenFavou::run()
    {
        sf::Event event;
        sf::RenderStates state;
        while (favWindow.isOpen()) {
            while (favWindow.pollEvent(evnt)) {
                handleEvent(evnt); // Pass the event to handleEvents
            }
            update();
            draw(favWindow, state);
            favWindow.display();
        }
    }

    void ScreenFavou::handleEvent(const sf::Event &evnt)
    {
        if (evnt.type == sf::Event::Closed)
            favWindow.close();
        else if (evnt.type == sf::Event::MouseMoved)
        {
            int XMouse = evnt.mouseMove.x;
            int YMouse = evnt.mouseMove.y;
            if (AddButton.isTouching(sf::Vector2f(XMouse, YMouse))) AddButton.buttonText.setFillColor(sf::Color::Red);
            else AddButton.buttonText.setFillColor(sf::Color::Black);

            if (ViewButton.isTouching(sf::Vector2f(XMouse, YMouse))) ViewButton.buttonText.setFillColor(sf::Color::Red);
            else ViewButton.buttonText.setFillColor(sf::Color::Black);

            if (DeleteButton.isTouching(sf::Vector2f(XMouse, YMouse))) DeleteButton.buttonText.setFillColor(sf::Color::Red);
            else DeleteButton.buttonText.setFillColor(sf::Color::Black);

            if (getBack.isTouching(sf::Vector2f(XMouse, YMouse)))
            {
                leftArrow.loadFromFile("data/images/red_arrow.png");
                getBack.buttonRec.setTexture(&leftArrow);
            }
            else
            {
                leftArrow.loadFromFile("data/images/black_arrow.png");
                getBack.buttonRec.setTexture(&leftArrow);
            
            }
            
        }

        else if (evnt.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos(evnt.mouseButton.x, evnt.mouseButton.y);
            
            if (evnt.mouseButton.button == sf::Mouse::Left) {
                if (AddButton.isTouching(mousePos)) {
                    std::cout << "Choosing add a new word" << std::endl;
                    AddBox.setTextBox(sf::Vector2f(266.0f, 50.0f), 668.0f, 200.0f, sf::Color::White, 2.0f, sf::Color::Black);
                    for (int i = 0; i < 10; i++) {
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

                else if (DeleteButton.isTouching(mousePos)) {
                    std::cout << "Choosing delete a word" << std::endl;
                    AddBox.setTextBox(sf::Vector2f(266.0f, 50.0f), 668.0f, 200.0f, sf::Color::White, 2.0f, sf::Color::Black);
                    text_input = "";
                    def_input  = "";
                    for (int i = 0; i < 10; i++) {
                        view[i].setString("");
                    }
                    HeadWord.setString("");
                    AddBox.boxText.setString(text_input);
                    DefBox.boxText.setString(def_input);
                    AddBox.writeThis = true;
                    option           = -1;
                }

                else if (ViewButton.isTouching(mousePos)) {
                    text_input     = "";
                    def_input      = "";
                    headword_input = "";
                    HeadWord.setString("");
                    AddBox.boxText.setString(text_input);
                    DefBox.boxText.setString(def_input);

                    std::cout << "Choosing view words" << std::endl;
                    for (int i = 0; i < 10; i++) {
                        std::string name = "data/" + dic_type + "/favourite.txt";
                        std::string str = takeLine(i + 1, name);
                        for (int j = 0; j < str.size(); j++) {
                            if (str[j] == '\t') {
                                std::string word = str.substr(0, j);
                                std::string def  = str.substr(j + 1);
                                str              = word + " : " + def;
                                // std::cout << str << std::endl;
                                view[i].setString(str);
                                break;
                            }
                        }
                    }
                }
                else if (getBack.isTouching(mousePos))
                {
                    setCallHome(true);
                    std::cout << "Choosing Back to main Screen" <<std::endl;
                }
            }
        }

        if (evnt.type == sf::Event::TextEntered && option != 0) {
            if (AddBox.writeThis && !DefBox.writeThis) AddBox.writing(evnt, text_input);
            if (AddBox.writeThis == false && DefBox.writeThis == false) {
                sf::Color headColor(255, 80, 80);
                HeadWord.setFillColor(headColor);
                headword_input = "  " + text_input;
                HeadWord.setString(headword_input);
                DefBox.boxText.setFillColor(sf::Color::Black);
                // def_input = "Definition goes at here";
                if (option > 0) {
                    std::cout << "Add to favourite list: " << text_input << std::endl;

                    // HANDLE BACK END ADD TO FAVOURITE LIST
                    std::string fileName = "data/" + dic_type + "/data.txt";
                    def_input            = defOfWord(text_input, fileName);
                    if (!def_input.size()) def_input = "ERROR: Can not find this word";
                    else {
                        if (defOfWord(text_input, "data/slang/favourite.txt") == "") // Not in the data/favourite.txt yet
                            addToEndOfFile(text_input, "data/slang/favourite.txt", fileName);
                        else {
                            def_input = "Already in the favourite list";
                            std::cout << "Word already in the favourite list" << std::endl;
                        }
                    }
                    option = 0;
                }

                if (option < 0) {
                    std::cout << "Delete from favourite list: " << text_input << std::endl;

                    // HANDLE BACK END DELETE FROM THE FAVOURITE LIST
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
                // DefBox.writeThis = true; USE THIS IF WANT TO CHANGE DEFINITION
            }
            // DefBox.writing(evnt, def_input); USE THIS IF WANT TO CHANGE THE DEFINITION
        }
    }


    void ScreenFavou::update()
    {
       
    }

  void ScreenFavou::draw(sf::RenderTarget& favWindow, sf::RenderStates states) const
    {
        favWindow.clear();
        favWindow.draw(Background);
        favWindow.draw(title);
        favWindow.draw(textTitle);
        favWindow.draw(getBack.buttonRec);
        AddButton.draw(favWindow);
        ViewButton.draw(favWindow);
        DeleteButton.draw(favWindow);
        AddBox.draw(favWindow);
        DefBox.draw(favWindow);
        favWindow.draw(HeadWord);
        for (int i = 0; i < 10; i++) {
            favWindow.draw(view[i]);
        }
    }
}