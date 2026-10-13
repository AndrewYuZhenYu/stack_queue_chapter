#include <iostream>
#include "applications.h"
#include "interactive.h"

int main() {
    do {
        int value = 0;
        int base = 0;
        if (!read_int("输入十进制整数：", value)) break;
        if (!read_int_range("目标进制（2–16）：", 2, 16, base)) break;
        std::cout << "转换结果：" << convert_base(value, base) << '\n';
    } while (run_again());
}
