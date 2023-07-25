#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
public:
    Textbox() {}

    Textbox(int size, sf::Color color, bool sel) {
        textbox.scale(2.f, 2.f);
        textbox.setCharacterSize(size);
        textbox.setFillColor(color);
        isSelected = sel;
        if (sel) {
            textbox.setString("_");
        }
        else {
            textbox.setString("");
        }
    }

    void create(int size, sf::Color color, bool sel) {
        textbox.scale(2.f, 2.f);
        textbox.setCharacterSize(size);
        textbox.setFillColor(color);
        isSelected = sel;
        if (sel) {
            textbox.setString("_");
        }
        else {
            textbox.setString("");
        }
    }

    void setTextColor(sf::Color color) {
        textbox.setFillColor(color);
    }

    void setImage(sf::Texture texture) {
        sprite.setScale(sf::Vector2f(0.15f, 0.15f));
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(800.f, 200.f));      
    }

    void setFont(sf::Font& font) {
        textbox.setFont(font);
    }

    void setPosition(sf::Vector2f pos) {
        textbox.setPosition(pos);
    }

    void setLimit(bool ToF) {
        hasLimit = ToF;
    }

    void setLimit(bool ToF, int lim) {
        hasLimit = ToF;
        limit = lim;
    }

    void setSelected(bool sel) {
        isSelected = sel;
        if (!sel) {
            std::string t = text.str();
            std::string newT = "";
            for (int i = 0; i < t.length() - 1; i++) {
                newT += t[i];
            }
            textbox.setString(newT);
        }
    }

    std::string getText() {
        return text.str();
    }

    void drawTo(sf::RenderWindow& window) {
        window.draw(textbox);
        window.draw(sprite);
    }

    void typedOn(sf::Event input) {
        if (isSelected) {
            int charTyped = input.text.unicode;
            if (charTyped < 128) {
                if (hasLimit) {
                    if (text.str().length() <= limit) {
                        inputLogic(charTyped);
                    }
                    else if (text.str().length() > limit && charTyped == DELETE_KEY) {
                        deleteLastChar();
                    }
                }
                else {
                    inputLogic(charTyped);
                }
            }
        }
    }

    bool isMouseOver(sf::RenderWindow& window) {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        //Left, top boundary
        float btnPosX = textbox.getPosition().x;
        float btnPosY = textbox.getPosition().y;

        //Right, bottom boundary
        float btnxPosWidth = btnPosX + textbox.getLocalBounds().width;
        float btnyPosHeight = btnPosY + textbox.getLocalBounds().height;

        if (mouseX <btnxPosWidth && mouseX > btnPosX && mouseY<btnyPosHeight && mouseY>btnPosY) return 1;
        return 0;
    }

private:
    sf::Text textbox;
    sf::Sprite sprite;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit = 20;

    void inputLogic(int charTyped) {
        if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
            text << static_cast<char>(charTyped);
        }
        else if (charTyped == DELETE_KEY) {
            if (text.str().length() > 0) {
                deleteLastChar();
            }
        }
        textbox.setString(text.str() + "_");
    }

    void deleteLastChar() {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length() - 1; i++) {
            newT += t[i];
        }
        text.str("");
        text << newT;

        textbox.setString(text.str());
    }
};
