#include <iostream>
#include "stack.h"

int main() {
    FixedStack stack(2);
    std::cout << "初始为空=" << stack.empty() << '\n';
    stack.push(10);
    stack.push(20);
    std::cout << "栈顶=" << *stack.top() << "，长度=" << stack.size() << '\n';
    std::cout << "从栈底到栈顶遍历：";
    for (int value : stack.bottom_to_top()) std::cout << value << ' ';
    std::cout << "\n满栈继续入栈=" << stack.push(30) << '\n';
    std::cout << "出栈=" << *stack.pop() << "，新栈顶=" << *stack.top() << '\n';
    stack.clear();
    std::cout << "清空后出栈成功=" << stack.pop().has_value() << '\n';
}
