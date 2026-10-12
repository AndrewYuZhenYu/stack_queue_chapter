#include <iostream>
#include <vector>
#include "算法应用.h"

int main() {
    const std::vector<int> input{2, 3, 4, 0};
    int sum = 0;
    std::cout << "递归返回时："; recursive_unwind_sum(input, 0, sum, std::cout);
    std::cout << "\n显式栈模拟："; iterative_unwind_sum(input, std::cout);
    std::cout << '\n';
}
