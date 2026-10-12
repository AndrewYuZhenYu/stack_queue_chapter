#include <iostream>
#include "栈.h"

int main() {
    GrowingStack stack;
    for (int i = 1; i <= 100; ++i) stack.push(i);
    std::cout << "动态栈长度=" << stack.size() << "，分配容量=" << stack.capacity() << '\n';
    std::cout << "栈顶=" << *stack.top() << "，弹出=" << *stack.pop() << '\n';
    stack.clear();
    std::cout << "清空后为空=" << stack.empty() << '\n';
}
