#include <iostream>
#include <string>
#include "算法应用.h"

int main() {
    for (const std::string& line : {"ab#cd", "wrong@right", "##ok"})
        std::cout << line << " -> " << edit_line(line) << '\n';
}
