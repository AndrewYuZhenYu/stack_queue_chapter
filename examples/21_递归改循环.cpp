#include <iostream>
#include "算法应用.h"

int main() {
    std::cout << "递归版："; recursive_print(5, std::cout);
    std::cout << "\n循环版："; iterative_print(5, std::cout);
    std::cout << '\n';
}
