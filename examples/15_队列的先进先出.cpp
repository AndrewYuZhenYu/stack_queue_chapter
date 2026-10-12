#include <iostream>
#include "队列.h"

int main() {
    CircularQueue queue(3);
    for (int value : {1, 2, 3}) queue.enqueue(value);
    std::cout << "入队 1 2 3，出队：";
    while (auto value = queue.dequeue()) std::cout << *value << ' ';
    std::cout << '\n';
}
