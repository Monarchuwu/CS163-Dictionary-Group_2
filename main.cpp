//#include <SFML/Graphics.hpp>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setPosition(200, 300);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}
#include "src/addWord.h"

int main() {
    screen_addWord* screen = new screen_addWord();
    screen->handleEvent();
    return 0;
}
