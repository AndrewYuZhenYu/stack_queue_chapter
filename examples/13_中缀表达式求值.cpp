#include <iostream>
#include <string>
#include "expression.h"
#include "interactive.h"

int main() {
    std::cout << "输入整数四则表达式；支持括号与直接写在数字前的负号，例如 -8+5*2。\n";
    std::string expression;
    while (read_line("表达式（直接回车退出）：", expression) && !expression.empty()) {
        try { std::cout << "结果=" << evaluate_infix(expression) << '\n'; }
        catch (const std::exception& error) { std::cout << "计算失败：" << error.what() << '\n'; }
    }
}
