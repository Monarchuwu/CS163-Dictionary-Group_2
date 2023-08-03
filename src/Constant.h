#pragma once
#include <SFML/Graphics.hpp>

namespace constant {
    extern sf::Font fontArial;
    extern sf::Font fontOpenSans;

    enum Dataset {
        EngEng,
        EngVie,
        VieEng,
        Slang,
        Emoji
    };

    enum ModeSearch {
        SearchByWord,
        SearchByDefinition
    };

    void loadFont();
} // namespace constant