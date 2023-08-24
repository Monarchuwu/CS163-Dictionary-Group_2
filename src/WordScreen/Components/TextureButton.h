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
        bool isHovered(float mouseX, float mouseY);

        bool isClicked(const sf::Event& event);

        // Draw
        void draw(sf::RenderTarget& window) const;

        // Click event
        void onClick(const sf::Event& event, void (*handler)());

    public:
        TextureButton();

        TextureButton(int width, int height);

    protected:
        sf::Texture texture;
        sf::RectangleShape box;
    };
} // namespace sora