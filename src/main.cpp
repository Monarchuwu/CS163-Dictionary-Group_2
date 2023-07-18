#include <SFML/Graphics.hpp>
#include "Application.h"
#include "Constant.h"

int main() {
    constant::loadFont();

    Application app;
    app.run();

    return 0;
}
