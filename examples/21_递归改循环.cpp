#include <iostream>
#include "applications.h"
#include "interactive.h"

int main() {
    do {
        int n = 0;
        if (!read_int_range("起始整数 n（1–20）：", 1, 20, n)) break;
        std::cout << "递归版："; recursive_print(n, std::cout);
        std::cout << "\n循环版："; iterative_print(n, std::cout);
        std::cout << '\n';
    } while (run_again());
}
