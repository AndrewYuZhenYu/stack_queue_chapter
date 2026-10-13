#include <iostream>
#include <string>
#include "applications.h"
#include "interactive.h"

int main() {
    std::cout << "可输入包含普通字符以及 () [] {} 的表达式。\n";
    std::string expression;
    while (read_line("输入表达式（直接回车退出）：", expression) && !expression.empty())
        std::cout << (brackets_match(expression) ? "括号匹配正确\n" : "括号不匹配\n");
}
