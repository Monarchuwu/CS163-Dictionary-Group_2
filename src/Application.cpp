#include "Application.h"
#include <iostream>

Application::Application()
    : mWindow(),
      mScreenMain(),
      screenfav() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    mWindow.create(sf::VideoMode(1600, 900), "Dictionary - Group 2", sf::Style::Close, settings);
    mWindow.setPosition(sf::Vector2i(10, 10));

    mDataManager.setDataset(constant::Dataset::EngEng);
    mDataManager.setModeSearch(constant::ModeSearch::SearchByWord);
    mDataManager.loadData();
    screenfav.changeDir(constant::Dataset::EngEng);
    screenhis.changeDir(constant::Dataset::EngEng);

    mScreen = &mScreenMain;
}

void Application::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
        }

        mScreen->handleEvent(event);
        //screenfav.handleEvent(event);
        //mScreenMain.handleEvent(event);
    }
}

void Application::update() {
    { // handle dataset and mode search
        if (mScreen->getDataset()) {
            int dataset = mScreen->getInteger1();
            mScreen->setDataset(false);
            if (dataset != mDataManager.getDataset()) {
                mDataManager.saveData();
                mDataManager.setDataset(dataset);
                mDataManager.loadData();
                screenfav.changeDir(dataset);
                screenhis.changeDir(dataset);
                std::cout << "[INFO] Change dataset to " << dataset << std::endl;
            }
            return;
        }
        if (mScreen->getModeSearch()) {
            int modeSearch = mScreen->getInteger2();
            mScreen->setModeSearch(false);
            if (modeSearch != mDataManager.getModeSearch()) {
                mDataManager.setModeSearch(modeSearch);
                std::cout << "[INFO] Change modeSearch to " << modeSearch << std::endl;
            }
            return;
        }
    }

    /*if (mScreen == &mScreenMain) {
        std::cout << "Home Screen\n";
    }

    if (mScreen == &screenAddWord) {
        std::cout << "Add Word Screen\n";
    }

    if (mScreen == &screenfav) {
        std::cout << "Favorite Screen\n";
    }

    if (mScreen == &screenWordDef) {
        std::cout << "Word Definition Screen\n";
    }*/

    if (mScreen->getCallHome()) {
        mScreen->setCallHome(false);
        mScreen = &mScreenMain;
        return;
    }

    if (mScreen->getCallSearchText()) {
        if (mDataManager.getModeSearch() == constant::ModeSearch::SearchByWord) {
			std::cout << "[INFO] Search by word" << std::endl;

            // run search word
            std::string word = mScreen->getString1();
            mScreen->setCallSearchText(false);

            if (word == "") return;

            // go to word screen if word exists
            Words::Word* cur = mDataManager.searchWord(word);
            if (cur != nullptr) {
                std::cout << "Found word\n";
                std::cout << cur->word << "\n";
                for (std::string definition : cur->definitions) std::cout << definition << " ";
                std::cout << "\n";

                bool isFavorite = screenfav.inTheFile(cur->word);

                // Open the Word-Definition screen
                if (mScreen->getCallWordDefScreen()) {
                    mScreen->setCallWordDefScreen(false);
                    mScreen = &screenWordDef;

                    screenWordDef.setWord(cur);
                    screenWordDef.setFavorite(isFavorite);
                }
            }
            else {
                std::cout << "Not found word\n";
            }

            return;
        }
		else {
            std::cout << "[INFO] Search by definition" << std::endl;
            // run search definition
            std::string word = mScreen->getString1();
            mScreen->setCallSearchText(false);
            // go to word list screen
            std::vector<Words::Word*> listWord = mDataManager.searchDefinition(word);
            for (Words::Word*& wordPtr : listWord) {
                std::cout << " ----- " << wordPtr->word << std::endl;
			}
            std::cout << " ----- END OF LIST ----- " << std::endl;
        }
    }

    if (mScreen->getCallAddWordScreen()) {
        mScreen->setCallAddWordScreen(false);
        mScreen = &screenAddWord;
        return;
    }

    if (mScreen->getCallFavoriteList()) {
        mScreen->setCallFavoriteList(false);
        mScreen = &screenfav;
        return;
    }

    if (mScreen->getCallHistoryList()) {
        mScreen->setCallHistory(false);
        mScreen = &screenhis;
        return;
    }
    
    /* WORD SCREEN */
    if (mScreen->getUpdateDefinition()) {
        mScreen->setUpdateDefinition(false);

        Words::Word* currentWord  = screenWordDef.getWord();
        std::string newDefinition = screenWordDef.getCurrentDefinition();
        std::string oldDefinition = currentWord->definitions[screenWordDef.getCurrentIndex()];
        std::cout << oldDefinition << " -> " << newDefinition << "\n";

        // replace an old with a new definition
        mDataManager.deleteDefinition(oldDefinition, currentWord->index);
        mDataManager.addDefinition(newDefinition, currentWord->index);
    }

    if (mScreen->getFavoriteToggled()) {
        mScreen->setFavoriteToggled(false);

        Words::Word* currentWord = screenWordDef.getWord();
        bool isFavorite          = screenWordDef.getFavorite();
        if (isFavorite) {
            screenfav.addAWord(currentWord->word);
        }
        else {
            screenfav.deleteAWord(currentWord->word);
        }
    }

    mScreen->update();
    // screenfav.update();
    //mScreenMain.update();

}

void Application::render() {
    mWindow.clear(sf::Color::Black);

    mScreen->draw(mWindow);
    //screenfav.draw(mWindow);
    //mScreenMain.draw(mWindow);

    mWindow.display();
}