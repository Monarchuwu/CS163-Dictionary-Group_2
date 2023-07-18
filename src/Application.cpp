#include "Application.h"
#include <iostream>

Application::Application()
    : mWindow() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    mWindow.create(sf::VideoMode(1600, 900), "Dictionary - Group 2", sf::Style::Close, settings);
    mWindow.setPosition(sf::Vector2i(10, 10));
}

void Application::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;

            case sf::Event::KeyReleased:
                if (sf::Keyboard::A <= event.key.code && event.key.code <= sf::Keyboard::Z) {
                    mString += char(event.key.code + 'a');
                }
                else if (event.key.code == sf::Keyboard::Delete) mString.pop_back();
                break;
        }
    }
}

void Application::update() {
}

void Application::render() {
    mWindow.clear(sf::Color::Black);

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(100, 100));
    mWindow.draw(rect);

    sf::Text mText;
    mText.setFont(constant::fontArial);
    mText.setStyle(sf::Text::Bold);
    mText.setCharacterSize(30);
    mText.setFillColor(sf::Color::Cyan);
    mText.setString(mString);
    mWindow.draw(mText);

    mWindow.display();
}