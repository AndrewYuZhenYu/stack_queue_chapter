#include <iostream>
#include "interactive.h"
#include "stack.h"

int main() {
    LinkedStack stack;
    int choice = 0;
    while (read_int_range("\n链栈：1 入栈 2 出栈 3 看栈顶 4 长度 5 清空 0 退出：",
                          0, 5, choice)) {
        if (choice == 0) break;
        if (choice == 1) {
            int value = 0;
            if (!read_int("入栈整数：", value)) break;
            stack.push(value);
            std::cout << "入栈成功\n";
        } else if (choice == 2) {
            auto value = stack.pop();
            if (value) std::cout << "出栈：" << *value << '\n';
            else std::cout << "空栈：下溢\n";
        } else if (choice == 3) {
            auto value = stack.top();
            if (value) std::cout << "栈顶：" << *value << '\n';
            else std::cout << "当前为空栈\n";
        } else if (choice == 4) {
            std::cout << "长度=" << stack.size() << '\n';
        } else {
            stack.clear();
            std::cout << "已清空\n";
        }
    }
}
