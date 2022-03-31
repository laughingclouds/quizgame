#include <unistd.h>

namespace app_display_op {
    void refreshScreen() {
        /**
        First byte: \x1b | escape character | decmial 27
        Rest: [2J

        escape sequence always starts with escape character followed by "["
        command: J | Erase in display
        argument: 2 | Clear entire screen

        refer: https://vt100.net/docs/vt100-ug/chapter3.html#ED
        **/
        write(STDOUT_FILENO, "\x1b[2J", 4);
    }
}