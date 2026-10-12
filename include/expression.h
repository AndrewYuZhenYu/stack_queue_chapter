#pragma once

#include <string>
#include <vector>

struct Token {
    char kind; // 'n' 表示整数，其余为运算符或括号。
    int number = 0;
};

std::vector<Token> tokenize(const std::string& text);
int evaluate_infix(const std::string& text);
std::vector<Token> to_postfix(const std::string& text);
int evaluate_postfix(const std::vector<Token>& tokens);
std::string show_postfix(const std::vector<Token>& tokens);
std::string to_prefix(const std::vector<Token>& postfix);
