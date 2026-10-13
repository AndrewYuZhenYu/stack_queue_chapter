#include "interactive.h"

#include <iostream>
#include <sstream>

bool read_line(const std::string& prompt, std::string& value) {
    std::cout << prompt << std::flush;
    return static_cast<bool>(std::getline(std::cin, value));
}

bool read_int(const std::string& prompt, int& value) {
    std::string line;
    while (read_line(prompt, line)) {
        std::istringstream input(line);
        int parsed = 0;
        input >> parsed;
        if (input) {
            input >> std::ws;
            if (input.eof()) { value = parsed; return true; }
        }
        std::cout << "请输入一个完整的整数。\n";
    }
    return false;
}

bool read_int_range(const std::string& prompt, int minimum, int maximum, int& value) {
    while (read_int(prompt, value)) {
        if (value >= minimum && value <= maximum) return true;
        std::cout << "请输入 " << minimum << " 到 " << maximum << " 之间的整数。\n";
    }
    return false;
}

bool run_again() {
    std::string answer;
    while (read_line("回车继续，输入 q 退出：", answer)) {
        if (answer.empty()) return true;
        if (answer == "q" || answer == "Q") return false;
        std::cout << "请直接回车，或输入 q。\n";
    }
    return false;
}
