#include <iostream>
#include "queue.h"

int main() {
    LinearQueue queue(3);
    for (int value : {10, 20, 30}) queue.enqueue(value);
    queue.dequeue();
    queue.dequeue();
    std::cout << "当前长度=" << queue.size() << "，继续入队成功=" << queue.enqueue(40)
              << "（数组前部虽有空槽，rear 已到末端）\n";
}
