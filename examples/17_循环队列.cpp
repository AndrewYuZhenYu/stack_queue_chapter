#include <iostream>
#include "queue.h"

int main() {
    CircularQueue queue(3);
    for (int value : {10, 20, 30}) queue.enqueue(value);
    std::cout << "满=" << queue.full() << "，继续入队=" << queue.enqueue(40) << '\n';
    std::cout << "出队 " << *queue.dequeue() << ' ' << *queue.dequeue() << '\n';
    queue.enqueue(40);
    queue.enqueue(50);
    std::cout << "回绕后，从队头到队尾：";
    for (int value : queue.front_to_rear()) std::cout << value << ' ';
    std::cout << "\n长度=" << queue.size() << "，队头=" << *queue.front() << '\n';
    queue.clear();
    std::cout << "清空后为空=" << queue.empty() << '\n';
}
