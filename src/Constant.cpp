#include <iostream>
#include "Constant.h"

namespace constant {
    sf::Font fontArial;
    sf::Font fontOpenSans;

	void loadFont() {
		if (!fontArial.loadFromFile("data/fonts/arial.ttf")) {
			std::cout << "Can't load the font !!!";
			exit(0);
		}
		if (!fontOpenSans.loadFromFile("data/fonts/Open_Sans/OpenSans.ttf")) {
			std::cout << "Can't load the font !!!";
			exit(0);
		}
	}
} // namespace constant