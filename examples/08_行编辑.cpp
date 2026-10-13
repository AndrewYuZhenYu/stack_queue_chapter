#include <iostream>
#include <string>
#include "applications.h"
#include "interactive.h"

int main() {
    std::cout << "输入一行文本：# 删除前一个字符，@ 清空当前行。\n";
    std::string line;
    while (read_line("原始文本（直接回车退出）：", line) && !line.empty())
        std::cout << "编辑结果：" << edit_line(line) << '\n';
}
