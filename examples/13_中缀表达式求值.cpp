#include <iostream>
#include <string>
#include "表达式.h"

int main() {
    for (const std::string& expression : {"4+2*3-10/5", "(12-3)*4", "-8+5*2"})
        std::cout << expression << " = " << evaluate_infix(expression) << '\n';
    try { evaluate_infix("4/(2-2)"); }
    catch (const std::exception& error) { std::cout << "错误示例：" << error.what() << '\n'; }
}
