#include <iostream>
#include <string>
#include "applications.h"

int main() {
    for (const std::string& line : {"ab#cd", "wrong@right", "##ok"})
        std::cout << line << " -> " << edit_line(line) << '\n';
}
