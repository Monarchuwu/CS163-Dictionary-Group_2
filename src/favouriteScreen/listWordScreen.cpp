#include "listWordScreen.h"

namespace minh {
    ScreenListWord::ScreenListWord() {
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

        textTitle.setFont(constant::fontOpenSans);
        textTitle.setCharacterSize(50);
        textTitle.setFillColor(sf::Color::Black);
        textTitle.setPosition(670.0f, 50.0f);
        textTitle.setString("WORD LIST");

        ViewButton.setButton(sf::Vector2f(266.0f, 50.0f), 668.0f, 135.0f, sf::Color::White, 2.0f, sf::Color::Black);
        ViewButton.setTextButton(750.0f, 135.0f, constant::fontOpenSans, 40, "VIEW", sf::Color::Black);

        getBack.buttonRec.setSize(sf::Vector2f(100.0f, 100.0f));
        getBack.buttonRec.setOutlineThickness(2.0f);
        getBack.buttonRec.setOutlineColor(sf::Color::Black);
        getBack.buttonRec.setPosition(1450.0f, 30.0f);
        leftArrow.loadFromFile("data/images/black_arrow.png");
        getBack.buttonRec.setTexture(&leftArrow);

        DefBox.setTextBox(sf::Vector2f(1400, 620.0f), 100.0f, 260.0f, sf::Color(222, 222, 222), 2.0f, sf::Color::Transparent);
        DefBox.setText(130.0f, 350.0f, constant::fontOpenSans, 40, "", sf::Color::Transparent);

        for (int i = 0; i < 11; i++) {
            view[i].setPosition(150.0f, 300.0f + i * 50.0f);
            view[i].setFillColor(sf::Color::Black);
            view[i].setFont(constant::fontOpenSans);
        }
    }

    void ScreenListWord::setListWord(const std::vector<std::string>& listWord) {
        this->listWord = listWord;
    }

    void ScreenListWord::handleEvent(const sf::Event& evnt) {
        if (evnt.type == sf::Event::MouseMoved) {
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
                if (listWord.size() > 10 * (page + 1)) {
                    page++;
                    std::cout << "View word at page: " << page + 1 << std::endl;
                }
            }
            for (int i = 0; i < 10 && i + 10 * page < listWord.size(); i++) {
                view[i].setString(listWord[i + 10 * page]);
            }
            std::string pageNum = std::to_string(page + 1);
            view[10].setString("PAGE: " + pageNum + " (Use Right/Left arrow to move between pages)");
            view[10].setFillColor(sf::Color(1, 49, 116));
        }

        else if (evnt.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos(evnt.mouseButton.x, evnt.mouseButton.y);

            if (evnt.mouseButton.button == sf::Mouse::Left) {
                if (ViewButton.isTouching(mousePos)) {
                    text_input = "";

                    std::cout << "Choosing view words" << std::endl;
                    isView = 1;
                    page   = 0;
                    std::cout << "View Word at page 1\n";
                    for (int i = 0; i < 10 && i + 10 * page < listWord.size(); i++) {
                        view[i].setString(listWord[i + 10 * page]);
                    }
                    std::string pageNum = std::to_string(page + 1);
                    view[10].setString("PAGE: " + pageNum + " (Use Right/Left arrow to move between pages)");
                    view[10].setFillColor(sf::Color(1, 49, 116));
                }
                else if (getBack.isTouching(mousePos)) {
                    setCallHome(true);
                    std::cout << "Choosing Back to main Screen" << std::endl;
                    for (int i = 0; i < 11; i++) {
                        view[i].setString("");
                    }
                }
            }
        }
    }

    void ScreenListWord::update() {
    }

    void ScreenListWord::draw(sf::RenderTarget& favWindow, sf::RenderStates states) const {
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
} // namespace minh