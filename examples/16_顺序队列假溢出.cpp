#include <iostream>
#include "interactive.h"
#include "queue.h"

int main() {
    std::cout << "非循环队列：即使前面已有空位，rear 到数组末端后仍无法入队。\n";
    int capacity = 0;
    if (!read_int_range("容量（1–20）：", 1, 20, capacity)) return 0;
    LinearQueue queue(static_cast<std::size_t>(capacity));
    int choice = 0;
    while (read_int_range("\n1 入队 2 出队 3 查看长度 0 退出：", 0, 3, choice)) {
        if (choice == 0) break;
        if (choice == 1) {
            int value = 0;
            if (!read_int("入队整数：", value)) break;
            std::cout << (queue.enqueue(value) ? "入队成功\n" : "rear 已到末端，无法入队（可能是假溢出）\n");
        } else if (choice == 2) {
            auto value = queue.dequeue();
            if (value) std::cout << "出队：" << *value << '\n';
            else std::cout << "队列为空\n";
        } else {
            std::cout << "当前长度=" << queue.size() << '\n';
        }
    }
}
