#include <cstdlib>

void clear_screen() {
#ifdef WINDOWS
  std::system("cls");
#else
  std::system("clear");
#endif
}