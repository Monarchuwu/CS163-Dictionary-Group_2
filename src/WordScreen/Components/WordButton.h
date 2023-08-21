#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>

namespace sora {

    class WordButton {
    protected:
        sf::RectangleShape box;
        sf::Text text;

    public:
        // Content
        void setContent(std::string content);

        // Font
        void setFont(sf::Font& font);

        // Button Size
        void setSize(int width, int height);

        // Text Size
        void setTextSize(int size);

        // Background Color
        void setBackgroundColor(sf::Color color);

        // Text Color
        void setTextColor(sf::Color color);

        // Position
        void setPosition(int x, int y);

        bool isHovered(float mouseX, float mouseY);

        bool isClicked(const sf::Event& event);

    public:
        WordButton();

        WordButton(std::string title, int width, int height, int textSize, sf::Font& font, sf::Color bgColor, sf::Color textColor);

        // Draw
        void draw(sf::RenderTarget& window) const;

        // Click event
        void onClick(const sf::Event& event, void (*handler)());
    };
} // namespace sora