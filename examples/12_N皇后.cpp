#include <iostream>
#include "applications.h"

int main() {
    std::vector<std::vector<int>> solutions = solve_n_queens(4);
    for (std::size_t i = 0; i < solutions.size(); ++i) {
        std::cout << "解 " << i + 1 << "（各行的列号）：";
        for (int col : solutions[i]) std::cout << col + 1 << ' ';
        std::cout << '\n';
    }
    std::cout << "总解数=" << solutions.size() << '\n';
}
