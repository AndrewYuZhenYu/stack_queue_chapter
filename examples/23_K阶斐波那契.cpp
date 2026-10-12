#include <iostream>
#include "applications.h"

int main() {
    const int k = 3;
    const int maximum = 20;
    KStepResult result = k_step_fibonacci(k, maximum);
    std::cout << "k=" << k << "，max=" << maximum << "，不超过 max 的项：";
    for (int value : result.terms) std::cout << value << ' ';
    std::cout << "\n窗口中最后 k 项：";
    for (int value : result.window) std::cout << value << ' ';
    std::cout << "\n下一项=" << result.next << "（超过 max）\n";
}
