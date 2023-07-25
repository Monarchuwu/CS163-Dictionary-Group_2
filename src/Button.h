#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

class Button {
public:
    Button() {}

    Button(sf::String t, sf::Vector2f size, sf::Color bgColor, int charSize, sf::Color textColor) {
        text.setScale(2, 2);
        text.setString(t);
        text.setFillColor(textColor);
        text.setCharacterSize(charSize);   
        content.setScale(1.5, 1.5);

        button.setSize(size);
        button.setFillColor(bgColor);
    }

    void create(sf::String t, sf::Vector2f size, sf::Color bgColor, int charSize, sf::Color textColor) {
        text.setScale(2, 2);
        text.setString(t);
        text.setFillColor(textColor);
        text.setCharacterSize(charSize);
        content.setScale(1.5, 1.5);

        button.setSize(size);
        button.setFillColor(bgColor);
    }

    void specialBtn(sf::Vector2f pos) {
        text.setScale(1.6, 1.6);

        button.setPosition(pos);
        float xPos = pos.x + 30;
        float yPos = pos.y + 10;

        text.setPosition({ xPos,yPos });
    }

    void setContent(sf::String t) {
        content.setString(t);
        content.setFillColor(sf::Color::White);
        content.setFont(*text.getFont());

        std::string tmp = content.getString();
        int getScalex;
        if (tmp.length() > 7) {
            content.setScale(1, 1);
            getScalex = 1;
        }
        else {
            content.setScale(1.5, 1.5);
            getScalex = 2;
        }

        float xPos = (button.getPosition().x + button.getLocalBounds().width / 2) - (content.getLocalBounds().width*getScalex / 2);
        float yPos = (button.getPosition().y + button.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2);
        
        content.setPosition({ xPos,yPos });
    }

    void setFont(sf::Font& font) {
        text.setFont(font);
    }

    void setBackColor(sf::Color color) {
        button.setFillColor(color);
    }

    void settextColor(sf::Color color) {
        text.setFillColor(color);
    }

    void setPosition(sf::Vector2f pos) {
        button.setPosition(pos);

        float xPos = (pos.x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
        float yPos = (pos.y + button.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2);
        text.setPosition({ xPos,yPos });
    }

    void setSize(sf::Vector2f size) {
        button.setSize(size);
    }

    void drawTo(sf::RenderWindow& window) {
        window.draw(button);
        window.draw(text);
        window.draw(content);
    }

    bool isMouseOver(sf::RenderWindow& window) {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        //Left, top boundary
        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;

        //Right, bottom boundary
        float btnxPosWidth = btnPosX + button.getLocalBounds().width;
        float btnyPosHeight = btnPosY + button.getLocalBounds().height;

        if (mouseX <btnxPosWidth && mouseX > btnPosX && mouseY<btnyPosHeight && mouseY>btnPosY) return 1;
        return 0;
    }

    void moveTextToTop() {
        text.setPosition({ 750,220 });
    }

public:
    sf::RectangleShape button;
    sf::Text text;
    sf::Text content;
};

