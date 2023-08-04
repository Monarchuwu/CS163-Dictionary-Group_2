#include <SFML/Graphics.hpp>
#include <iostream>

namespace sora {
    class TextureButton {
    public:
        // Button Size
        void setSize(int width, int height);

        // Texture
        void setTextureByLink(std::string link);

        // Position
        void setPosition(int x, int y);

        // Check mouse over
        bool isHovered(sf::RenderWindow& window);

        bool isClicked(sf::RenderWindow& window);

        // Draw
        void draw(sf::RenderWindow& window);

        // Click event
        void onClick(sf::RenderWindow& window, void (*handler)());

    public:
        TextureButton();

        TextureButton(int width, int height);

    protected:
        sf::Texture texture;
        sf::RectangleShape box;
    };
} // namespace sora