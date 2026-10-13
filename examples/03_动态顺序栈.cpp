#include <iostream>
#include "interactive.h"
#include "stack.h"

int main() {
    GrowingStack stack;
    int choice = 0;
    while (read_int_range("\n动态栈：1 入栈 2 出栈 3 看栈顶 4 遍历 5 清空 6 容量 0 退出：",
                          0, 6, choice)) {
        if (choice == 0) break;
        if (choice == 1) {
            int value = 0;
            if (!read_int("入栈整数：", value)) break;
            std::size_t before = stack.capacity();
            stack.push(value);
            std::cout << "入栈成功；长度=" << stack.size() << "，容量=" << stack.capacity();
            if (stack.capacity() != before) std::cout << "（发生扩容）";
            std::cout << '\n';
        } else if (choice == 2) {
            auto value = stack.pop();
            if (value) std::cout << "出栈：" << *value << '\n';
            else std::cout << "空栈：下溢\n";
        } else if (choice == 3) {
            auto value = stack.top();
            if (value) std::cout << "栈顶：" << *value << '\n';
            else std::cout << "当前为空栈\n";
        } else if (choice == 4) {
            std::cout << "栈底 -> 栈顶：";
            for (int value : stack.bottom_to_top()) std::cout << value << ' ';
            std::cout << '\n';
        } else if (choice == 5) {
            stack.clear();
            std::cout << "已清空\n";
        } else {
            std::cout << "长度=" << stack.size() << "，已分配容量=" << stack.capacity() << '\n';
        }
    }
}
