#include <iostream>
#include <string>
#include "expression.h"
#include "interactive.h"

int main() {
    std::cout << "输入中缀表达式，观察前缀、后缀表示与后缀求值。\n";
    std::string expression;
    while (read_line("中缀表达式（直接回车退出）：", expression) && !expression.empty()) {
        try {
            std::vector<Token> postfix = to_postfix(expression);
            std::cout << "前缀：" << to_prefix(postfix) << '\n';
            std::cout << "后缀：" << show_postfix(postfix) << '\n';
            std::cout << "计算结果：" << evaluate_postfix(postfix) << '\n';
        } catch (const std::exception& error) {
            std::cout << "转换失败：" << error.what() << '\n';
        }
    }
}
