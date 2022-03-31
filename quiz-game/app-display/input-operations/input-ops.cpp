#include <cstdlib>
#include <iostream>
#include <ncurses.h>

#include "../terminal-operations/terminal-ops.hpp"
#include "../../quiz-game.hpp"

namespace app_display_op {
namespace input {
void processKeypress() {
    char c = terminal::readKey();

    switch (c) {
        /**
        Close application after saving everything
        **/
        case CTRL_KEY('q'):
            std::exit(0);
            break;
        /**
        Say hello for now
        **/
        case CTRL_KEY('h'):
            std::cout << "Hey, lol\r\n";
            break;
        /**
        Save or start
        **/
        case CTRL_KEY('s'):
            std::cout << "Starting now!\r\n";
            break;
        // case unctrl():
            std::cout << "It's working\r\n";
            break;
				case KEY_F(1):
					std::cout << "F1 key pressed\r\n";
					break;
    }
}
}
} // namespace app_display_op