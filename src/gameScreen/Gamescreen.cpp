#include "Button_game.h"
#include <SFML/Graphics.hpp>
#include "RandomSpace.h"

class GameScreen {
public:
    sf::RenderWindow window;
    sf::Font feather;

    //TrieWord tree = TrieWord();
    randomSpace rd = randomSpace();
    int page = 0;
    int ind = 0;
    int liveleft = 2;
    int record = 0;
    int result = 0;
    bool ansYet = 0;
    bool isQuit = 0;
    bool active = 1;
    std::string dataFile = ".\\File\\tmp2.txt";

    sf::Text live;
    sf::Text showResult;
    sf::Text quote;

    //Textbox
    Button nothing1;
    Button nothing2;

    Button cancel;
    Button qbox;
    Button word;
    Button A;
    Button B;
    Button C;
    Button D;
    
    //Texture
    sf::Texture humpback;
    sf::Texture ferien;
    sf::Texture book;
    sf::Texture diamond;
    sf::Texture ufo;
    sf::Texture heart;
    sf::Texture fish;
    sf::Texture fire;
    sf::Texture nap;
    sf::Texture home;
    sf::Texture quit;
    sf::Texture end;
    sf::Texture keep;
    sf::Texture cont;
    sf::Texture gotit;
    sf::Texture sad;
    sf::Texture contblue;
    sf::Texture happy;

    //Sprite
    sf::Sprite image1;
    sf::Sprite nth1s;
    sf::Sprite nth2s;
    sf::Sprite nth3s;
    sf::Sprite nth4s;

    sf::Sprite humpbacks;
    sf::Sprite feriens;
    sf::Sprite books;
    sf::Sprite diamonds;
    sf::Sprite ufos;
    sf::Sprite hearts;
    sf::Sprite fishs;
    sf::Sprite fires;
    sf::Sprite naps;
    sf::Sprite homes;
    sf::Sprite quits;
    sf::Sprite ends;
    sf::Sprite keeps;
    sf::Sprite conts;
    sf::Sprite gotits;
    sf::Sprite yesnos;
    sf::Sprite sads;
    sf::Sprite contblues;
    sf::Sprite happys;

    //vector
    std::vector<sf::Color> pagewhite = { sf::Color(225, 236, 241, 255) ,sf::Color(54,92,113,255)};
    //std::vector<sf::Color> pagenotwhite = { sf::Color(240, 240, 240), sf::Color(119, 119, 119) };
    //std::vector<sf::Color> color = { sf::Color(254, 254, 254), sf::Color(254, 254, 254), sf::Color(254, 254, 254) };
    std::vector<sf::Sprite> image;
    std::vector< std::vector<sf::Vector2f> > posi;
    std::vector<Button*> ansButton;

    GameScreen() {
        window.create(sf::VideoMode(1200, 900), "SFML works!");

        //Font
        if (!feather.loadFromFile("feather.ttf")) std::cout << "False";

        //Text
        //live
        live.setString(std::to_string(liveleft));
        live.setScale(1.4, 1.4);
        live.setFont(feather);
        live.setFillColor(sf::Color(230, 86, 79));
        live.setPosition(1130, 42);

        //showRecord
        showResult.setScale(1.2, 1.2);
        showResult.setFont(feather);
        showResult.setFillColor(sf::Color(65, 65, 65));
        showResult.setPosition(500, 560);

        //quote
        quote.setScale(1.1, 1.1);
        quote.setFont(feather);
        quote.setFillColor(sf::Color(175, 175, 175));
        quote.setPosition(300, 670);

        //Textbox
        // nothing
        nothing2.create("", { 0,0 }, sf::Color::Transparent, sf::Color::White, { 0,0 }, feather, 0);

        // cancel
        cancel.create("Quit?", { 1200.f, 600.f }, sf::Color(245, 245, 245), sf::Color(75, 75, 75), { 0,450 }, feather, 30);
        cancel.setContent();
        cancel.content.setPosition({ 550,500 });
        cancel.setcontentColor(sf::Color(75,75,75));
        cancel.content.setScale(1.2, 1.2);
        cancel.setunderlay();
        cancel.underlay.setFillColor(sf::Color(245, 245, 245, 150));
        cancel.underlay.setSize({1200,900});
        cancel.underlay.setPosition({ 0,0 });

        // qbox
        qbox.create("Question", {400.f, 120.f}, sf::Color::Transparent, sf::Color(75, 75, 75), {340,0}, feather, 20);
        qbox.setContent();
        qbox.setcontentColor(sf::Color(175, 175, 175));
        qbox.content.setScale(1.5, 1.5);

        // word
        word.create("Text", { 300.f, 220.f }, sf::Color::Transparent, sf::Color(246, 246, 246), { 380,50 }, feather, 20);
        word.setContent();
        word.setcontentColor(sf::Color(75, 75, 75));
        
        //A
        sf::Vector2f sizeABCD = { 400.f, 220.f };
        A.create("A", sizeABCD, pagewhite[0], pagewhite[1], {110,280}, feather, 30);
        //A.setContent();
        A.setunderlay();

        //B
        B.create("B", sizeABCD, pagewhite[0], pagewhite[1], { 690,280 }, feather, 30);
       // B.setContent();
        B.setunderlay();

        //C
        C.create("C", sizeABCD, pagewhite[0], pagewhite[1], { 110,560 }, feather, 30);
       // C.setContent();
        C.setunderlay();

        //D
        D.create("D", sizeABCD, pagewhite[0], pagewhite[1], { 690,560 }, feather, 30);
        //D.setContent();
        D.setunderlay();

        //Image
        //humpbacks
        if (!humpback.loadFromFile(".\\Image\\Humpback.PNG")) std::cout << "False";
        humpbacks.setTexture(humpback);
        humpbacks.setScale(sf::Vector2f(0.2f, 0.2f));
        humpbacks.setPosition(sf::Vector2f(12.f, 55.f));

        //feriens
        if (!ferien.loadFromFile(".\\Image\\Ferien.PNG")) std::cout << "False";
        feriens.setTexture(ferien);
        feriens.setScale(sf::Vector2f(0.2f, 0.2f));
        feriens.setPosition(sf::Vector2f(15.f, 58.f));

        //books
        if (!book.loadFromFile(".\\Image\\Book.PNG")) std::cout << "False";
        books.setTexture(book);
        books.setScale(sf::Vector2f(0.2f, 0.2f));
        books.setPosition(sf::Vector2f(15.f, 58.f));

        //diamonds
        if (!diamond.loadFromFile(".\\Image\\Diamond.PNG")) std::cout << "False";
        diamonds.setTexture(diamond);
        diamonds.setScale(sf::Vector2f(0.17f, 0.17f));
        diamonds.setPosition(sf::Vector2f(900.f, 58.f));

        //ufos
        if (!ufo.loadFromFile(".\\Image\\UFO.PNG")) std::cout << "False";
        ufos.setTexture(ufo);
        ufos.setScale(sf::Vector2f(0.2f, 0.2f));
        ufos.setPosition(sf::Vector2f(800.f, 60.f));

        //hearts
        if (!heart.loadFromFile(".\\Image\\Heart.PNG")) std::cout << "False";
        hearts.setTexture(heart);
        hearts.setScale(sf::Vector2f(0.15f, 0.15f));
        hearts.setPosition(sf::Vector2f(1050.f, 22.f));

        //fishs
        if (!fish.loadFromFile(".\\Image\\Fish.PNG")) std::cout << "False";
        fishs.setTexture(fish);
        fishs.setScale(sf::Vector2f(0.5f, 0.5f));
        fishs.setPosition(sf::Vector2f(820.f, 52.f));

        //fires
        if (!fire.loadFromFile(".\\Image\\Fire.PNG")) std::cout << "False";
        fires.setTexture(fire);
        fires.setScale(sf::Vector2f(0.19f, 0.19f));
        fires.setPosition(sf::Vector2f(15.f, 41.f));

        //naps
        if (!nap.loadFromFile(".\\Image\\Nap.PNG")) std::cout << "False";
        naps.setTexture(nap);
        naps.setScale(sf::Vector2f(0.25f, 0.25f));
        naps.setPosition(sf::Vector2f(850.f, 60.f));

        //homes
        if (!home.loadFromFile(".\\Image\\Home_x.PNG")) std::cout << "False";
        homes.setTexture(home);
        homes.setScale(sf::Vector2f(0.12f, 0.12f));
        homes.setPosition(sf::Vector2f(15.f, 15.f));

        //quits
        if (!quit.loadFromFile(".\\Image\\Quit.PNG")) std::cout << "False";
        quits.setTexture(quit);
        quits.setScale(sf::Vector2f(0.5f, 0.5f));
        quits.setPosition(sf::Vector2f(400.f, 550.f));
        
        //ends
        if (!end.loadFromFile(".\\Image\\End.png")) std::cout << "False";
        ends.setTexture(end);
        ends.setScale(sf::Vector2f(0.32f, 0.32f));
        ends.setPosition(sf::Vector2f(120.f, 620.f));

        //keeps
        if (!keep.loadFromFile(".\\Image\\Keep.png")) std::cout << "False";
        keeps.setTexture(keep);
        keeps.setScale(sf::Vector2f(0.53f, 0.53f));
        keeps.setPosition(sf::Vector2f(740.f, 620.f));

        //conts
        if (!cont.loadFromFile(".\\Image\\Cont.png")) std::cout << "False";
        conts.setTexture(cont);
        conts.setScale(sf::Vector2f(0.7f, 0.7f));
        conts.setPosition(sf::Vector2f(360.f, 765.f));

        //gotits
        if (!gotit.loadFromFile(".\\Image\\Gotit.png")) std::cout << "False";
        gotits.setTexture(gotit);
        gotits.setScale(sf::Vector2f(0.7f, 0.7f));
        gotits.setPosition(sf::Vector2f(350.f, 765.f));

        //sads
        if (!sad.loadFromFile(".\\Image\\Sad.png")) std::cout << "False";
        sads.setTexture(sad);
        sads.setScale(sf::Vector2f(0.42f, 0.42f));
        sads.setPosition(sf::Vector2f(280.f, 180.f));

        //contblues
        if (!contblue.loadFromFile(".\\Image\\Cont_blue.png")) std::cout << "False";
        contblues.setTexture(contblue);
        contblues.setScale(sf::Vector2f(0.6f, 0.6f));
        contblues.setPosition(sf::Vector2f(350.f, 700.f));

        //happys
        if (!happy.loadFromFile(".\\Image\\Happy.png")) std::cout << "False";
        happys.setTexture(happy);
        happys.setScale(sf::Vector2f(0.4f, 0.4f));
        happys.setPosition(sf::Vector2f(325.f, 160.f));

        //Sprite nth
        image = { feriens, diamonds, fires, fishs, books, naps };

        //vector posi
        ansButton = { &A, &B, &C, &D };
        for (int i = 0; i < 4; i++) {
            std::vector<sf::Vector2f> tmp_v = {};
            posi.push_back(tmp_v);
            *(posi.end() - 1) = getPosiButton(*ansButton[i]);
        }

        //Random
        rd.readFile(".\\File\\gamebank.txt");
        loadQues();

        //File
        readRecord();
    }

    std::vector<sf::Vector2f> getPosiButton(Button tmp) {
        float x = tmp.button.getPosition().x;
        float y = tmp.button.getPosition().y;

        float xwidth = x + tmp.button.getLocalBounds().width;
        float yheight = y + tmp.button.getLocalBounds().height;

        return { {x,y},{xwidth, yheight} };
    }

    void readRecord() {
        std::ifstream fin(".\\File\\Record.txt");

        std::string tmp;
        fin >> tmp;
        record = std::stoi(tmp);
        fin.close();
    }

    bool isClick(sf::Sprite tmp) {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float x = tmp.getPosition().x;
        float y = tmp.getPosition().y;

        float xwidth = x + tmp.getLocalBounds().width*tmp.getScale().x;
        float yheight = y + tmp.getLocalBounds().height*tmp.getScale().y;

        if (mouseX > x && mouseX <xwidth && mouseY >y && mouseY < yheight) return 1;
        return 0;
    }

    bool isClick_button(Button tmp) {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float x = tmp.button.getPosition().x;
        float y = tmp.button.getPosition().y;

        float xwidth = x + tmp.button.getLocalBounds().width;
        float yheight = y + tmp.button.getLocalBounds().height;

        if (mouseX > x && mouseX <xwidth && mouseY >y && mouseY < yheight) return 1;
        return 0;
    }

    void isClick_home() {
        if (isClick(homes)) {
            isQuit = 1;
            nothing1 = cancel;
            nth1s = quits;
            nth2s = ends;
            nth3s = keeps;
        }
    }

    void isClick_keep() {
        if (isClick(keeps)) {
            isQuit = 0;
            nothing1 = nothing2;
            nth1s = nth4s;
            nth2s = nth4s;
            nth3s = nth4s;
        }
    }

    void isClick_yesno() {
        if (isClick(yesnos)) {
            yesnos = nth4s;
            ansYet = 0;
            ind++;
            loadQues();
            page++;
            changeColor();
        }
    }

    void isClick_cont() {
        if (isClick(nth2s)) window.close(); 
    }

    void isClick_end() {
        if (isClick(nth2s)) window.close();
    }

    void changeColor () {
        if (page > image.size()-1) page = 0;
        if (page < 0) page = image.size()-1;

        image1 = image[page];
        /*
        A.setBackColor(pagewhite[0]);
        B.setBackColor(pagewhite[0]);
        C.setBackColor(pagewhite[0]);
        D.setBackColor(pagewhite[0]);

        A.setcontentColor(pagewhite[1]);
        B.setcontentColor(pagewhite[1]);
        C.setcontentColor(pagewhite[1]);
        D.setcontentColor(pagewhite[1]);

        word.setcontentColor(sf::Color(75, 75, 75));
        if (color[page] == sf::Color(254, 254, 254)) {
            A.setBackColor(pagewhite[0]);
            B.setBackColor(pagewhite[0]);
            C.setBackColor(pagewhite[0]);
            D.setBackColor(pagewhite[0]);

            A.settextColor(pagewhite[1]);
            B.settextColor(pagewhite[1]);
            C.settextColor(pagewhite[1]);
            D.settextColor(pagewhite[1]);

            word.setcontentColor(sf::Color(75, 75, 75));
        }

        else if (color[page] != sf::Color(254, 254, 254)) {
            A.setBackColor(pagenotwhite[0]);
            B.setBackColor(pagenotwhite[0]);
            C.setBackColor(pagenotwhite[0]);
            D.setBackColor(pagenotwhite[0]);

            A.settextColor(pagenotwhite[1]);
            B.settextColor(pagenotwhite[1]);
            C.settextColor(pagenotwhite[1]);
            D.settextColor(pagenotwhite[1]);

            word.setcontentColor(sf::Color(247, 247, 247));
        }
        */
  }


    void loadQues() {
        if (ind >= rd.listAns.size()) ind = 0;
        word.content.setString(rd.listQues[ind]);

        float xPos = (word.button.getPosition().x + word.button.getLocalBounds().width / 2) - (word.content.getLocalBounds().width / 2);
        float yPos = (word.button.getPosition().y + word.button.getLocalBounds().height / 2) - (word.content.getLocalBounds().height / 2);
        word.content.setPosition({ xPos+40,yPos });

        qbox.content.setString("Question " + std::to_string(ind + 1));

        for (int i = 0; i < 4; i++) {
            ansButton[i]->text.setString(rd.listChoice[ind][i]);
            ansButton[i]->setSpecial();
            ansButton[i]->setBackColor(pagewhite[0]);
            ansButton[i]->settextColor(pagewhite[1]);
        }
        /*
        A.text.setString(rd.listChoice[ind][0]);
        B.text.setString(rd.listChoice[ind][1]);
        C.text.setString(rd.listChoice[ind][2]);
        D.text.setString(rd.listChoice[ind][3]);
        
        A.setSpecial();
        B.setSpecial();
        C.setSpecial();
        D.setSpecial();
        */
 }

    void checkAns(int ans) {
        if (ans == rd.listAns[ind]) {
           ansButton[ans]->setBackColor(sf::Color(214, 255, 184));
           ansButton[ans]->settextColor(sf::Color(87, 167, 0));
           yesnos = conts;
           result++;
           return;
        }

        ansButton[ans]->setBackColor(sf::Color(255, 223, 223));
        ansButton[ans]->settextColor(sf::Color(234, 42, 42));
        ansButton[rd.listAns[ind]]->setBackColor(sf::Color(sf::Color(214, 255, 184)));
        ansButton[rd.listAns[ind]]->settextColor(sf::Color(87, 167, 0));
        yesnos = gotits;
        liveleft--;
        live.setString(std::to_string(liveleft));
    }

    void endGame() {
        active = 0;

        cancel.button.setPosition({ 0,0 });
        cancel.button.setFillColor(sf::Color(254, 254, 253));
        cancel.setSize({ 1200,900 });

        nothing1 = cancel;   
        nth2s = contblues;

        if (result <= record) {
            nth1s = sads;
            showResult.setString("Result: " + std::to_string(result) + '\n' + "Record: " + std::to_string(record) + '\n');
            showResult.setPosition(500, 560);
            quote.setString("Don't worry! Practice makes perfect.");
            quote.setPosition(300, 670);
        }

        if (result > record) {
            nth1s = happys;
            showResult.setString("Your new record: " + std::to_string(result));
            showResult.setPosition(420, 580);
            quote.setString("Awesome!");
            quote.setPosition(500, 650);
        }
    }

    //handle event
    void handleEvent() {
        sf::Event event;
        while (window.isOpen()) {
            changeColor();
            while (window.pollEvent(event)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (!active) isClick_cont();
                    if (liveleft == 0) endGame();
                    if (active) isClick_home();

                    for (int i = 0; i < 4;i++) { 
                        if (isClick_button(*ansButton[i]) && !ansYet && !isQuit && active) {
                            checkAns(i);
                            ansYet = 1;
                            break;
                        }
                    }

                    if (isQuit && active) {
                        isClick_keep();
                        isClick_end();
                    }

                    if (ansYet && !isQuit && active) isClick_yesno();
                    
                }

                switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                }
                draw();
            }
        }
    }

    void draw() {
        window.clear(sf::Color(254, 254, 254));

        window.draw(image1);
        window.draw(hearts);
        window.draw(homes);
        window.draw(live);
        window.draw(yesnos);

        A.drawTo(window);
        B.drawTo(window);
        C.drawTo(window);
        D.drawTo(window);
        word.drawTo(window);
        qbox.drawTo(window);

        nothing1.drawTo(window);
        window.draw(nth1s);
        window.draw(nth2s);
        window.draw(nth3s);
        window.draw(showResult);
        window.draw(quote);
        
        window.display();
    }
};

