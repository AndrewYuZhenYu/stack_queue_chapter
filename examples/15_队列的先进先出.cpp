#include <iostream>
#include "interactive.h"
#include "queue.h"

int main() {
    std::cout << "先进先出实验：自行输入入队顺序，再观察出队顺序。\n";
    int count = 0;
    while (read_int_range("元素个数（1–10，0 退出）：", 0, 10, count) && count != 0) {
        CircularQueue queue(static_cast<std::size_t>(count));
        for (int i = 0; i < count; ++i) {
            int value = 0;
            if (!read_int("第 " + std::to_string(i + 1) + " 个整数：", value)) return 0;
            queue.enqueue(value);
        }
        std::cout << "依次出队：";
        while (auto value = queue.dequeue()) std::cout << *value << ' ';
        std::cout << '\n';
    }
}
