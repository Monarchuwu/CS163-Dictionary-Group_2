#include "Constant.h"
#include <iostream>

namespace constant {
    sf::Font fontArial;

    sf::Color BACKGROUND_COLOR = sf::Color(255, 255, 153);
    sf::Color YELLOW = sf::Color::Yellow;
    sf::Color BLACK  = sf::Color::Black;
    sf::Color WHITE  = sf::Color::White;

    int appWidth = 1600;
    int appHeight = 900;

    void loadFont() {
        if (!fontArial.loadFromFile("data/fonts/arial.ttf")) {
            std::cout << "Can't load the font !!!";
            exit(0);
        }
    }
} // namespace constant