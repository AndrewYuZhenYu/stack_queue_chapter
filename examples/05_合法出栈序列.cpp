#include <iostream>
#include "applications.h"
#include "interactive.h"

int main() {
    std::cout << "输入 1..n 的固定入栈顺序，枚举所有合法出栈顺序。S=入栈，X=出栈。\n";
    int n = 0;
    while (read_int_range("n（1–5，0 退出）：", 0, 5, n) && n != 0) {
        auto results = stack_sequences(n);
        for (const StackSequence& sequence : results) {
            for (int value : sequence.output) std::cout << value << ' ';
            std::cout << "  操作=" << sequence.actions << '\n';
        }
        std::cout << "共有 " << results.size() << " 种。\n";
    }
}
