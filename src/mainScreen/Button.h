#pragma once
#include "Box.h"
#include "PressMethod.h"

namespace mainScreen {
    // A Box that can be pressed
    class Button : public Box, public PressMethod {
    public:
        // Default constructor
        Button(const sf::Vector2f& size = sf::Vector2f(0, 0));
    };
} // namespace mainScreen