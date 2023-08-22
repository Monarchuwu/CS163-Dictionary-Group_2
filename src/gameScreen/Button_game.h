#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <sstream>

class Button {
public:
    Button() {}

    void create(sf::String t, sf::Vector2f size, sf::Color bgColor, sf::Color textColor, sf::Vector2f pos, sf::Font& font, int charSize) {
        button.setSize(size);
        button.setFillColor(bgColor);

        text.setScale(1.5, 1.5);
        text.setString(t);
        text.setFillColor(textColor);
        text.setCharacterSize(charSize);

        setFont(font);
        setPosition(pos);
    }
    
    void setSpecial() {
        std::string s = text.getString();
        float xPos = (button.getPosition().x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
        float yPos = (button.getPosition().y + button.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2);

        if (s.length() < 16) {
            text.setScale(1.25, 1.25);
            text.setPosition(xPos-16, yPos-10);
            return;
        }

        std::string tmp;
        std::string f = "";
        std::stringstream ss(s);

        for (int i = 0; i < 4; i++) {
            ss >> tmp;
            f += tmp + " ";
            if (ss.tellg() == -1) break;
            if (i == 1) f += '\n';
            if (i == 3 && ss.tellg() != -1) f += "...";
        }

        text.setString(f);
        text.setScale(1, 1);
        xPos = (button.getPosition().x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
        yPos = (button.getPosition().y + button.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2);
        text.setPosition(xPos + 12, yPos - 8);
    }

    void setunderlay() {
        underlay.setSize(button.getSize());
        underlay.setFillColor(sf::Color(75, 75, 75, 60));
        underlay.setPosition({ button.getPosition().x+8, button.getPosition().y+8});
        
    }
         
    void setFont(sf::Font& font) {
        text.setFont(font);
    }

    void setContent() {
        content.setString(text.getString());
        content.setFillColor(sf::Color(247,247,247));
        content.setFont(*text.getFont());
        text.setString("");
        content.setScale(text.getScale());

        float xPos = (button.getPosition().x + button.getLocalBounds().width / 2) - (content.getLocalBounds().width / 2);
        float yPos = (button.getPosition().y + button.getLocalBounds().height / 2) - (content.getLocalBounds().height / 2);

        content.setPosition({ xPos,yPos });
    }

    void setBackColor(sf::Color color) {
        button.setFillColor(color);
    }

    void settextColor(sf::Color color) {
        text.setFillColor(color);
    }

    void setcontentColor(sf::Color color) {
        content.setFillColor(color);
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

    void drawTo(sf::RenderTarget& window) const {
        window.draw(underlay);
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

public:
    sf::RectangleShape button;
    sf::RectangleShape underlay;
    sf::Text text;
    sf::Text content;
};


