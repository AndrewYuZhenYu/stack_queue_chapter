#pragma once

#include <string>

// 返回 false 表示输入流结束（例如 Ctrl+D），调用方应正常退出。
bool read_line(const std::string& prompt, std::string& value);
bool read_int(const std::string& prompt, int& value);
bool read_int_range(const std::string& prompt, int minimum, int maximum, int& value);
bool run_again();
