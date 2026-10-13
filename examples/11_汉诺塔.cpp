#include <iostream>
#include "applications.h"
#include "interactive.h"

int main() {
    std::cout << "把圆盘从 A 经 B 移到 C。\n";
    do {
        int n = 0;
        if (!read_int_range("圆盘数（1–7）：", 1, 7, n)) break;
        hanoi_moves(n, 'A', 'B', 'C', std::cout);
        std::cout << "共需 " << (1 << n) - 1 << " 步。\n";
    } while (run_again());
}
