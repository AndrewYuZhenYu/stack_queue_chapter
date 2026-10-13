#include <iostream>
#include "interactive.h"
#include "stack.h"

int main() {
    int capacity = 0;
    if (!read_int_range("设置顺序栈容量（1–100）：", 1, 100, capacity)) return 0;
    FixedStack stack(static_cast<std::size_t>(capacity));
    int choice = 0;
    while (read_int_range("\n1 入栈 2 出栈 3 看栈顶 4 遍历 5 清空 6 状态 0 退出：", 0, 6, choice)) {
        if (choice == 0) break;
        if (choice == 1) {
            int value = 0;
            if (!read_int("入栈整数：", value)) break;
            std::cout << (stack.push(value) ? "入栈成功\n" : "栈满：上溢，入栈失败\n");
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
            std::cout << "长度=" << stack.size() << "，容量=" << stack.capacity()
                      << "，空=" << stack.empty() << "，满=" << stack.full() << '\n';
        }
    }
}
