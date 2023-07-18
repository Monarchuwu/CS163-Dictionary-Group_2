#pragma once
#include <SFML/Graphics.hpp>
#include "ContainMethod.h"
#include "PressMethod.h"
#include "HideMethod.h"

namespace mainScreen {
    class ButtonSprite : public sf::Sprite, public ContainMethod, public PressMethod, public HideMethod {
    public:
        // default constructor
        ButtonSprite();

        // constructor with texture
        ButtonSprite(const sf::Texture& texture);

        // constructor with link to texture
        ButtonSprite(const std::string& string);

        // set texture of button
        void setTexture(const sf::Texture& texture);

        // get texture of button
        const sf::Texture* getTexture() const;

        // set link to texture of button
        void setTextureLink(const std::string& string);

        // check if point in Button
        bool isContain(sf::Vector2f point) const override;
        bool isContain(float x, float y) const override;

    private:
        // set texture of button (internal)
        void setTexture();

    private:
        // texture of button
        sf::Texture mTexture;
    };
} // namespace mainScreen