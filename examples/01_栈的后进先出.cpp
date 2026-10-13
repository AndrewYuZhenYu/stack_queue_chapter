#include <iostream>
#include "interactive.h"
#include "stack.h"

int main() {
    std::cout << "后进先出实验：自行输入入栈顺序，再观察出栈顺序。\n";
    int count = 0;
    while (read_int_range("元素个数（1–10，0 退出）：", 0, 10, count) && count != 0) {
        FixedStack stack(static_cast<std::size_t>(count));
        for (int i = 0; i < count; ++i) {
            int value = 0;
            if (!read_int("第 " + std::to_string(i + 1) + " 个整数：", value)) return 0;
            stack.push(value);
        }
        std::cout << "依次出栈：";
        while (auto value = stack.pop()) std::cout << *value << ' ';
        std::cout << '\n';
    }
}
