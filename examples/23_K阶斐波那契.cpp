#include <iostream>
#include "applications.h"
#include "interactive.h"

int main() {
    do {
        int k = 0, maximum = 0;
        if (!read_int_range("阶数 k（2–10）：", 2, 10, k)) break;
        if (!read_int_range("最大值 max（1–1000000）：", 1, 1000000, maximum)) break;
        KStepResult result = k_step_fibonacci(k, maximum);
        std::cout << "不超过 max 的项：";
        for (int value : result.terms) std::cout << value << ' ';
        std::cout << "\n循环队列中最后 k 项：";
        for (int value : result.window) std::cout << value << ' ';
        std::cout << "\n下一项=" << result.next << "（超过 max）\n";
    } while (run_again());
}
