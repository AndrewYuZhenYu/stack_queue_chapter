#include <iostream>
#include "interactive.h"
#include "queue.h"

int main() {
    LinkedQueue queue;
    int choice = 0;
    while (read_int_range("\n链队列：1 入队 2 出队 3 看队头 4 长度 5 清空 0 退出：",
                          0, 5, choice)) {
        if (choice == 0) break;
        if (choice == 1) {
            int value = 0;
            if (!read_int("入队整数：", value)) break;
            queue.enqueue(value);
            std::cout << "入队成功\n";
        } else if (choice == 2) {
            auto value = queue.dequeue();
            if (value) std::cout << "出队：" << *value << '\n';
            else std::cout << "队空：出队失败\n";
        } else if (choice == 3) {
            auto value = queue.front();
            if (value) std::cout << "队头：" << *value << '\n';
            else std::cout << "当前为空队列\n";
        } else if (choice == 4) {
            std::cout << "长度=" << queue.size() << '\n';
        } else {
            queue.clear();
            std::cout << "已清空\n";
        }
    }
}
