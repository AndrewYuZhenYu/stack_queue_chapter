#include <iostream>
#include <vector>
#include "applications.h"
#include "interactive.h"

int main() {
    std::cout << "依次输入整数，以 0 结束。观察递归返回与显式栈弹出的相同次序。\n";
    do {
        std::vector<int> input;
        for (int i = 0; i < 20; ++i) {
            int value = 0;
            if (!read_int_range("整数（-10000–10000，0 结束）：", -10000, 10000, value)) return 0;
            input.push_back(value);
            if (value == 0) break;
        }
        int sum = 0;
        std::cout << "递归返回时："; recursive_unwind_sum(input, 0, sum, std::cout);
        std::cout << "\n显式栈模拟："; iterative_unwind_sum(input, std::cout);
        std::cout << '\n';
    } while (run_again());
}
