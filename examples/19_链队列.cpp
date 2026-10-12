#include <iostream>
#include "queue.h"

int main() {
    LinkedQueue queue;
    queue.enqueue(7);
    std::cout << "队头=" << *queue.front() << "，出队=" << *queue.dequeue() << '\n';
    std::cout << "最后一个元素出队后为空=" << queue.empty() << '\n';
    queue.enqueue(8);
    queue.enqueue(9);
    std::cout << "再次入队后的顺序：";
    while (auto value = queue.dequeue()) std::cout << *value << ' ';
    std::cout << '\n';
}
