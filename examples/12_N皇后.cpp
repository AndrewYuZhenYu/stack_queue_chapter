#include <iostream>
#include "applications.h"
#include "interactive.h"

int main() {
    do {
        int n = 0, limit = 0;
        if (!read_int_range("棋盘大小 n（1–8）：", 1, 8, n)) break;
        if (!read_int_range("最多显示前几组解（0–10）：", 0, 10, limit)) break;
        auto solutions = solve_n_queens(n);
        std::cout << "总解数=" << solutions.size() << '\n';
        for (std::size_t i = 0; i < solutions.size() && i < static_cast<std::size_t>(limit); ++i) {
            std::cout << "解 " << i + 1 << "（每行的列号）：";
            for (int col : solutions[i]) std::cout << col + 1 << ' ';
            std::cout << '\n';
        }
    } while (run_again());
}
