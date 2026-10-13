#include <iostream>
#include "applications.h"
#include "interactive.h"

int main() {
    std::cout << "观察每层递归的进入和返回顺序。\n";
    do {
        int n = 0;
        if (!read_int_range("计算 n!，n（0–10）：", 0, 10, n)) break;
        int answer = trace_factorial(n, 0, std::cout);
        std::cout << "结果=" << answer << '\n';
    } while (run_again());
}
