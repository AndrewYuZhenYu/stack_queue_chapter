#include <iostream>
#include "栈.h"

int main() {
    FixedStack stack(3);
    for (int value : {1, 2, 3}) stack.push(value);
    std::cout << "入栈 1 2 3，出栈：";
    while (auto value = stack.pop()) std::cout << *value << ' ';
    std::cout << '\n';
}
