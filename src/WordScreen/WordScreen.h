#pragma once 
#include <SFML/Graphics.hpp>
#include "../Constant.h"
#include "../Screen.h"
#include "Components/all.h"

namespace sora {

    class WordScreen : public Screen {
        
    public:
        // Constructor
        WordScreen();

        // Destructor
        ~WordScreen();

    public:
        // Event Handler
        void handleEvent(sf::RenderWindow &window, sf::Event &event);

        // Update
        void update() override;

        // handle event
        void handleEvent(const sf::Event &event) override;

        // draw
        void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;

    /* BUTTON EVENT HANDLERS */
    public:
        // Change word
        void changeWord(std::string text);  

        void changeDefinition(std::string text);

        // Return to Home Screen
        void returnHomeScreen();

        // Open Word Screen
        void activate();

        void prevDefinition();

        void nextDefinition();

        void setDefinition();

        void setFavorite(bool type);

        void toggleFavorite();

        void setPage();

        void addDefinition();

        void deleteDefinition();

    // Database interaction
    public:
        void saveNewDefinition();

        void deleteWord();

    private:
        Label wordText;
        TextArea definitionText;
        WordButton prevBtn, nextBtn;
        TextureButton favoriteBtn, homeBtn, starBtn, wordDeleteButton;
        WordButton addDefBtn, deleteDefBtn;
        Label pageText;

        bool isActive = true;
        bool isFavorite = false;
        int wordId    = 5;
        int currentId = 0;
        std::string word   = "Interchangable";
        std::vector<std::string> definitions{ 
            "Hello test", 
            "Hello test 01", 
            "Hello test 02",
            "Hello test 03",
            "Hello test 04",
            "Hello test 05",
            "Hello test 06"

        };
    };
}