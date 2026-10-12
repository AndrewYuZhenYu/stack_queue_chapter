#include <iostream>
#include <string>
#include "表达式.h"

int main() {
    const std::string infix = "2*3+(8-6/2)*4";
    std::vector<Token> postfix = to_postfix(infix);
    std::cout << "中缀：" << infix << '\n';
    std::cout << "前缀：" << to_prefix(postfix) << '\n';
    std::cout << "后缀：" << show_postfix(postfix) << '\n';
    std::cout << "后缀求值：" << evaluate_postfix(postfix) << '\n';
}
