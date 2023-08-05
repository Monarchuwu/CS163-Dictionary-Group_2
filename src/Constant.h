#pragma once
#include <SFML/Graphics.hpp>

namespace constant {
	extern sf::Font fontArial;

	// Color
	extern sf::Color BACKGROUND_COLOR;
	extern sf::Color YELLOW;
	extern sf::Color BLACK;
	extern sf::Color WHITE;

	// Variables
	extern int appWidth, appHeight;

	void loadFont();
} // namespace constant