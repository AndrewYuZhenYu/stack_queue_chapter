#include <iostream>
#include "interactive.h"
#include "queue.h"

int main() {
    int capacity = 0;
    if (!read_int_range("循环队列容量（1–100）：", 1, 100, capacity)) return 0;
    CircularQueue queue(static_cast<std::size_t>(capacity));
    int choice = 0;
    while (read_int_range("\n1 入队 2 出队 3 看队头 4 遍历 5 状态 6 清空 0 退出：",
                          0, 6, choice)) {
        if (choice == 0) break;
        if (choice == 1) {
            int value = 0;
            if (!read_int("入队整数：", value)) break;
            std::cout << (queue.enqueue(value) ? "入队成功\n" : "队满：入队失败\n");
        } else if (choice == 2) {
            auto value = queue.dequeue();
            if (value) std::cout << "出队：" << *value << '\n';
            else std::cout << "队空：出队失败\n";
        } else if (choice == 3) {
            auto value = queue.front();
            if (value) std::cout << "队头：" << *value << '\n';
            else std::cout << "当前为空队列\n";
        } else if (choice == 4) {
            std::cout << "队头 -> 队尾：";
            for (int value : queue.front_to_rear()) std::cout << value << ' ';
            std::cout << '\n';
        } else if (choice == 5) {
            std::cout << "长度=" << queue.size() << "，容量=" << queue.capacity()
                      << "，空=" << queue.empty() << "，满=" << queue.full() << '\n';
        } else {
            queue.clear();
            std::cout << "已清空\n";
        }
    }
}
