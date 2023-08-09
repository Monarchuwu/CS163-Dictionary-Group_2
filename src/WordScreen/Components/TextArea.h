#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
namespace sora {
    class TextArea {
        // Content
    public:
        void setContent(std::string text);

        // Add character
        void addContent(char t);

        // Remove Character
        void deleteContent();

        // Font
        void setFont(sf::Font &font);

        // Text Size
        void setTextSize(int size);

        // Text color
        void setTextColor(sf::Color color);

        // Get content
        std::string getContent();

    private:
        // Focus and Blur
        void setFocus(bool type);

        void setDisplayText();

        // Box
    public:
        // Input size
        void setSize(int width, int height);

        // Background Color
        void setBackgroundColor(sf::Color color);

        // Position
        void setPosition(int x, int y);

        // TextArea
    public:
        TextArea();

        TextArea(int width, int height, int textSize, sf::Font &font, sf::Color textColor = sf::Color::Black, sf::Color bgColor = sf::Color::White);

    public:
        // Draw
        void draw(sf::RenderTarget &window) const;

        // Check mouse over
        bool isHovered(float mouseX, float mouseY);

        bool getFocused();

        // Click event
        void onClick(const sf::Event &event);

        void onType(const sf::Event &event);

        bool isClicked(const sf::Event &event);

        bool isOutClicked(const sf::Event &event);

    private:
        sf::RectangleShape box;
        sf::Text textHolder;
        std::string content = "";
        bool isFocused      = false;
    };
} // namespace sora