#include <iostream>
#include "栈.h"

int main() {
    LinkedStack stack;
    for (int value : {4, 5, 6}) stack.push(value);
    std::cout << "链栈长度=" << stack.size() << "，出栈：";
    while (auto value = stack.pop()) std::cout << *value << ' ';
    std::cout << "\n空栈弹出成功=" << stack.pop().has_value() << '\n';
}
