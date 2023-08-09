#pragma once
#include <SFML/Graphics.hpp>

namespace sora {
    class Label {
        // Content
    public:
        void setContent(std::string text);

        // Font
        void setFont(sf::Font &font);

        // Text Size
        void setTextSize(int size);

        // Text color
        void setTextColor(sf::Color color);

        // Box
    public:
        // Input size
        void setSize(int width, int height);

        // Background Color
        void setBackgroundColor(sf::Color color);

        // Position
        void setPosition(int x, int y);

        void setStyle(sf::Uint32 style);

        // Label
    public:
        Label();

        Label(std::string title, int width, int height, int textSize, sf::Font &font, sf::Color textColor = sf::Color::Black, sf::Color bgColor = sf::Color::White);

    public:
        // Draw
        void draw(sf::RenderTarget &window) const;

        // Check mouse over
        bool isHovered(sf::RenderTarget &window);

    private:
        sf::RectangleShape box;
        sf::Text textHolder;
        std::string content = "";
    };
} // namespace sora