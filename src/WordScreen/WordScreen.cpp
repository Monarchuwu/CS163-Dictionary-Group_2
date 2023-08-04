#include "WordScreen.h"

namespace sora{
    const int WordLabelWidth = 500;
    const int WordLabelHeight = 100;
    const int TextAreaWidth   = 750;
    const int TextAreaHeight  = 300;
    const int ControlButtonHeight = 50;
    const int ControlButtonWidth = 50;
    const int DefinitionButtonWidth = 250;
    const int DefinitionButtonHeight = 75;
    const int PageLabelWidth         = 250;
    const int PageLabelHeight        = 75;

    const std::string imagePath         = "data/images/";
    const std::string FAVORITE_STAR_IMG = "favorite_star.png";
    const std::string STAR_IMG          = "star.png";
    const std::string HOME_IMG          = "home.png";
    const std::string DELETE_IMG        = "delete.png";

    /* BUTTON EVENTS */


    // Constructor
    WordScreen::WordScreen() {
        std::cout << "[WORD SCREEN] Created!" << std::endl;

        wordText = Label("Cat", WordLabelWidth, WordLabelHeight, 48, constant::fontArial);
        wordText.setStyle(sf::Text::Bold | sf::Text::Italic);
        changeWord("interchangeable");

        pageText = Label("1/8", PageLabelWidth, PageLabelHeight, 28, constant::fontArial);
        pageText.setStyle(sf::Text::Bold);
        setPage();


        definitionText = TextArea(TextAreaWidth, TextAreaHeight, 24, constant::fontArial);
        definitionText.setPosition(constant::appWidth / 2 - TextAreaWidth / 2, 300);
        definitionText.setContent(definitions[currentId]);

        prevBtn = WordButton("<", ControlButtonHeight, ControlButtonWidth, 24, constant::fontArial, constant::WHITE, constant::BLACK);
        prevBtn.setPosition(constant::appWidth / 2 - TextAreaWidth / 2 - ControlButtonWidth - 30, 300 + TextAreaHeight / 2 - ControlButtonHeight / 2);

        nextBtn = WordButton(">", ControlButtonHeight, ControlButtonWidth, 24, constant::fontArial, constant::WHITE, constant::BLACK);
        nextBtn.setPosition(constant::appWidth / 2 + TextAreaWidth / 2 + 30, 300 + TextAreaHeight / 2 - ControlButtonHeight / 2);
    
        favoriteBtn.setSize(50, 50);
        favoriteBtn.setTextureByLink(imagePath + FAVORITE_STAR_IMG);
        favoriteBtn.setPosition(20, 20);

        starBtn.setSize(50, 50);
        starBtn.setTextureByLink(imagePath + STAR_IMG);
        starBtn.setPosition(20, 20);
        
        homeBtn.setSize(50, 50);
        homeBtn.setTextureByLink(imagePath + HOME_IMG);
        homeBtn.setPosition(100, 20);

        wordDeleteButton.setSize(50, 50);
        wordDeleteButton.setTextureByLink(imagePath + DELETE_IMG);
        wordDeleteButton.setPosition(180, 20);

        addDefBtn = WordButton("New Definition", DefinitionButtonWidth, DefinitionButtonHeight, 24, constant::fontArial, constant::WHITE, constant::BLACK);     
        addDefBtn.setPosition(constant::appWidth / 2 - TextAreaWidth / 2, 750);

        deleteDefBtn = WordButton("Remove Definition", DefinitionButtonWidth, DefinitionButtonHeight, 24, constant::fontArial, constant::WHITE, constant::BLACK);     
        deleteDefBtn.setPosition(constant::appWidth / 2 + TextAreaWidth / 2 - DefinitionButtonWidth, 750);

    }

    // Destructor
    WordScreen::~WordScreen() {
        std::cout << "[WORD SCREEN] Deleted!" << std::endl;
    }

    // Event Handler
    void WordScreen::handleEvent(sf::RenderWindow &window, sf::Event &event) {
        if (!isActive) {
            return;
        }

        definitionText.onClick(window, event);
        definitionText.onType(window, event);
        if (event.type == sf::Event::TextEntered) {
            int key = event.text.unicode;
            if (key == ENTER_KEY) saveNewDefinition();
        }
        if (definitionText.isOutClicked(window)) saveNewDefinition();
        
        if (homeBtn.isClicked(window)) returnHomeScreen();

        if (favoriteBtn.isClicked(window) && isFavorite) toggleFavorite();
        else if (starBtn.isClicked(window) && !isFavorite) toggleFavorite();

        if (prevBtn.isClicked(window)) prevDefinition();

        if (nextBtn.isClicked(window)) nextDefinition();

        if (wordDeleteButton.isClicked(window)) deleteWord();

        if (addDefBtn.isClicked(window)) addDefinition();

        if (deleteDefBtn.isClicked(window)) deleteDefinition();

    }

    // Update
    void WordScreen::update() {
        if (!isActive) {
            return;
        }
    }

    // Draw
    void WordScreen::draw(sf::RenderWindow &window) {
        if (!isActive) {
            window.clear(constant::BACKGROUND_COLOR);
            return;
        }
        wordText.draw(window);
        definitionText.draw(window);
        prevBtn.draw(window);
        nextBtn.draw(window);
        homeBtn.draw(window);
        wordDeleteButton.draw(window);
        if (isFavorite)
            favoriteBtn.draw(window);
        else
            starBtn.draw(window);
        addDefBtn.draw(window);
        deleteDefBtn.draw(window);
        pageText.draw(window);
    }

    void WordScreen::changeWord(std::string text) {
        wordText.setContent(text);
        int X = constant::appWidth / 2 - WordLabelWidth / 2;
        int Y = 20;
        wordText.setPosition(X, Y);
    }

    void WordScreen::changeDefinition(std::string text) {
        definitionText.setContent(text);
    }

    // Return to Home Screen
    void WordScreen::returnHomeScreen() {
        std::cout << "Heading back to [HOME SCREEN]...\n";
        isActive = false;
    }

    void WordScreen::activate() {
        std::cout << "[WORD SCREEN] activated...";
        isActive = true;
    }

    void WordScreen::prevDefinition() {
        --currentId;
        if (currentId < 0) currentId += definitions.size();
        setDefinition();
    }

    void WordScreen::nextDefinition() {
        ++currentId;
        if (currentId == definitions.size()) currentId = 0;
        setDefinition();
    }

    void WordScreen::setDefinition() {
        changeDefinition(definitions[currentId]);
        setPage();
    }

    void WordScreen::setFavorite(bool type) {
        isFavorite = type;
    }

    void WordScreen::toggleFavorite() {
        setFavorite(!isFavorite);
    }

    void WordScreen::setPage() {
        int X = constant::appWidth / 2 - PageLabelWidth / 2;
        int Y = 650;
        pageText.setPosition(X, Y);

        std::string page;
        page = std::to_string(currentId + 1) + "/" + std::to_string(definitions.size());
        pageText.setContent(page);
    }

    void WordScreen::addDefinition() {
        definitions.push_back("");
        currentId = definitions.size() - 1;
        setDefinition();
    }

    void WordScreen::deleteDefinition() {

    }

    // Database interaction
    void WordScreen::saveNewDefinition() {
        std::string content = definitionText.getContent();
        std::cout << "You have change: " + content << std::endl;
        definitions[currentId] = definitionText.getContent();
    }

    void WordScreen::deleteWord() {
        std::cout << "You have deleted " + word << std::endl;
        returnHomeScreen();
    }
}