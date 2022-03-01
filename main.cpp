#include <iostream>

#include "version.hpp"
using namespace std;

int main() {
    cout << NAME << '\n';
    cout << "Release: " << RELEASE << '\n';
    cout << "Version: " << VERSION << endl;

    return 0;
}