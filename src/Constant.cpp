#include <iostream>
#include "Constant.h"

namespace constant {
    sf::Font fontArial;

	void loadFont() {
		if (!fontArial.loadFromFile("data/fonts/arial.ttf")) {
			std::cout << "Can't load the font !!!";
			exit(0);
		}
	}
} // namespace constant