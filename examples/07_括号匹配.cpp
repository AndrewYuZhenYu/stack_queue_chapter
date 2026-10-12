#include <iostream>
#include <string>
#include "算法应用.h"

int main() {
    for (const std::string& text : {"a[(b+c)*{d-e}]", "([)]", "(()", ")("})
        std::cout << text << " -> " << (brackets_match(text) ? "匹配" : "不匹配") << '\n';
}
