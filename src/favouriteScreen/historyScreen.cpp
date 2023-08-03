
#include "historyScreen.h"
namespace minh {
    ScreenHis::ScreenHis() {
        // Picking the dictionary type
        dic_type = "test";
        
        // Initialize Window
        backgroundColor = sf::Color(113, 114, 115);
        Background.setSize(sf::Vector2f(1600.0f, 900.0f));
        Background.setFillColor(sf::Color::White);
        subBackground1.setSize(sf::Vector2f(1600.0f, 255.0f));
        subBackground1.setFillColor(backgroundColor);
        subBackground2.setSize(sf::Vector2f(1600.0f, 200.0f));
        subBackground2.setFillColor(sf::Color(1, 49, 116));
        // Setup font + object
        title.setSize(sf::Vector2f(800.0f, 100.0f));
        title.setOutlineThickness(2.0f);
        title.setOutlineColor(sf::Color::Black);
        title.setOrigin(400.0f, 50.0f);
        title.setPosition(800.0f, 80.0f);
        title.setFillColor(sf::Color::White);

        font.loadFromFile("data/fonts/Open_Sans/OpenSans.ttf");

        textTitle.setFont(font);
        textTitle.setCharacterSize(50);
        textTitle.setFillColor(sf::Color::Black);
        textTitle.setPosition(640.0f, 50.0f);
        textTitle.setString("HISTORY LIST");

      

        ViewButton.setButton(sf::Vector2f(266.0f, 50.0f), 668.0f, 135.0f, sf::Color::White, 2.0f, sf::Color::Black);
        ViewButton.setTextButton(750.0f, 135.0f, font, 40, "VIEW", sf::Color::Black);


        getBack.buttonRec.setSize(sf::Vector2f(100.0f, 100.0f));
        getBack.buttonRec.setOutlineThickness(2.0f);
        getBack.buttonRec.setOutlineColor(sf::Color::Black);
        getBack.buttonRec.setPosition(1300.0f, 30.0f);
        leftArrow.loadFromFile("data/images/black_arrow.png");
        getBack.buttonRec.setTexture(&leftArrow);

       

        DefBox.setTextBox(sf::Vector2f(1400, 620.0f), 100.0f, 260.0f, sf::Color(222, 222, 222), 2.0f, sf::Color::Transparent);
        DefBox.setText(130.0f, 350.0f, font, 40, "", sf::Color::Transparent);

        for (int i = 0; i < 11; i++) {
            view[i].setPosition(150.0f, 300.0f + i * 50.0f);
            view[i].setFillColor(sf::Color::Black);
            view[i].setFont(font);
        }

    }

    void ScreenHis::run() 
    {
        sf::Event evnt;
        sf::RenderStates state;
        while (hisWindow.isOpen()) {
            while (hisWindow.pollEvent(evnt)) {
                handleEvent(evnt); // Pass the event to handleEvents
            }
            update();
            draw(hisWindow, state);
            hisWindow.display();
        }
    }

    void ScreenHis::handleEvent(const sf::Event& evnt) {
        if (evnt.type == sf::Event::Closed)
            hisWindow.close();
        else if (evnt.type == sf::Event::MouseMoved) {
            int XMouse = evnt.mouseMove.x;
            int YMouse = evnt.mouseMove.y;
            

            if (ViewButton.isTouching(sf::Vector2f(XMouse, YMouse))) {
                ViewButton.buttonText.setFillColor(sf::Color::Red);
                ViewButton.buttonRec.setFillColor(sf::Color(222, 222, 222));
            }
            else {
                ViewButton.buttonText.setFillColor(sf::Color::Black);
                ViewButton.buttonRec.setFillColor(sf::Color::White);
            }

           

            if (getBack.isTouching(sf::Vector2f(XMouse, YMouse))) {
                leftArrow.loadFromFile("data/images/red_arrow.png");
                getBack.buttonRec.setTexture(&leftArrow);
            }
            else {
                leftArrow.loadFromFile("data/images/black_arrow.png");
                getBack.buttonRec.setTexture(&leftArrow);
            }
        }
        else if (evnt.type == sf::Event::KeyReleased && isView) {
            if (evnt.key.code == sf::Keyboard::Left)
                if (page > 0) {
                    page--;
                    std::cout << "View word at page: " << page + 1 << std::endl;
                }
            if (evnt.key.code == sf::Keyboard::Right) {
            
                std::string name = "data/" + dic_type + "/history.txt";
                std::string str  = takeLine(1 + 10 * (page + 1), name);
                if (str.size()) {
                    page++;
                    std::cout << "View word at page: " << page + 1 << std::endl;
                }
            }
            for (int i = 0; i < 10; i++) {
                std::string name = "data/" + dic_type + "/history.txt";
                std::string str  = takeLine(i + 1 + 10 * page, name);
                //for (int j = 0; j < str.size(); j++) {
                //    if (str[j] == '\t') {
                //        std::string word = str.substr(0, j);
                //        std::string def  = str.substr(j + 1);
                //        str              = word + " : " + def;
                   

                //        break;
                //    }
                //}
                //std::string str = "";
                view[i].setString(str);
            }
            std::string pageNum = std::to_string(page + 1);
            view[10].setString("PAGE: " + pageNum + " (Use Right/Left arrow to move between pages)");
            view[10].setFillColor(sf::Color(1, 49, 116));
        }

        else if (evnt.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos(evnt.mouseButton.x, evnt.mouseButton.y);

            if (evnt.mouseButton.button == sf::Mouse::Left) {
                
                if (ViewButton.isTouching(mousePos)) {
                    text_input     = "";
                  

                    std::cout << "Choosing view words" << std::endl;
                    isView = 1;
                    page   = 0;
                    std::cout << "View Word at page 1\n";
                    for (int i = 0; i < 10; i++) {
                        std::string name = "data/" + dic_type + "/history.txt";
                        std::string str  = takeLine(i + 1 + 10 * page, name);
                        //for (int j = 0; j < str.size(); j++) {
                        //    if (str[j] == '\t') {
                        //        std::string word = str.substr(0, j);
                        //        std::string def  = str.substr(j + 1);
                        //        str              = word + " : " + def;
                        //        // std::cout << str << std::endl;

                        //        break;
                        //    }
                        //}
                        //std::string str = "";
                        view[i].setString(str);
                    }
                    std::string pageNum = std::to_string(page + 1);
                    view[10].setString("PAGE: " + pageNum + " (Use Right/Left arrow to move between pages)");
                    view[10].setFillColor(sf::Color(1, 49, 116));
                }
                else if (getBack.isTouching(mousePos)) {
                    setCallHome(true);
                    std::cout << "Choosing Back to main Screen" << std::endl;
                }
            }
        }

       
    }

    void ScreenHis::update() {
    }

    void ScreenHis::draw(sf::RenderTarget& favWindow, sf::RenderStates states) const {
        favWindow.clear();
        favWindow.draw(Background);
        favWindow.draw(subBackground1);
        favWindow.draw(subBackground2);
        favWindow.draw(title);
        favWindow.draw(textTitle);
        favWindow.draw(getBack.buttonRec);
      
        ViewButton.draw(favWindow);
       
       DefBox.draw(favWindow);
    
        for (int i = 0; i < 11; i++) {
            favWindow.draw(view[i]);
        }
    }

    void ScreenHis::changeDir(int dataset) {
        switch (dataset) {
            case constant::Dataset::Slang: {
                dic_type = "slang";
                break;
            }

            default:
                dic_type = "test";
                break;
        }
    }
} // namespace minh