#include <iostream>
#include "队列.h"

int main() {
    CountingQueue queue(3);
    for (int value : {1, 2, 3}) queue.enqueue(value);
    std::cout << "3 个槽都使用，满=" << queue.full() << "，长度=" << queue.size() << '\n';
    std::cout << "出队=" << *queue.dequeue() << '\n';
    queue.enqueue(4);
    std::cout << "回绕后：";
    for (int value : queue.front_to_rear()) std::cout << value << ' ';
    std::cout << '\n';
}
