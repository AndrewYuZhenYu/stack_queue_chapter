#include "表达式.h"

#include <cctype>
#include <climits>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<Token> tokenize(const std::string& text) {
    std::vector<Token> result;
    bool want_number = true;
    for (std::size_t i = 0; i < text.size();) {
        unsigned char current = static_cast<unsigned char>(text[i]);
        if (std::isspace(current)) { ++i; continue; }
        bool signed_number = want_number && text[i] == '-' && i + 1 < text.size() &&
                             std::isdigit(static_cast<unsigned char>(text[i + 1]));
        if (std::isdigit(current) || signed_number) {
            if (!want_number) throw std::invalid_argument("missing operator");
            bool negative = signed_number;
            if (negative) ++i;
            long long value = 0;
            long long limit = negative ? static_cast<long long>(INT_MAX) + 1 : INT_MAX;
            while (i < text.size() && std::isdigit(static_cast<unsigned char>(text[i]))) {
                value = value * 10 + (text[i++] - '0');
                if (value > limit) throw std::out_of_range("integer literal out of range");
            }
            result.push_back({'n', static_cast<int>(negative ? -value : value)});
            want_number = false;
        } else if (text[i] == '(' && want_number) {
            result.push_back({'('}); ++i;
        } else if (text[i] == ')' && !want_number) {
            result.push_back({')'}); ++i;
        } else if (!want_number && (text[i] == '+' || text[i] == '-' ||
                                   text[i] == '*' || text[i] == '/')) {
            result.push_back({text[i++]});
            want_number = true;
        } else {
            throw std::invalid_argument("unexpected character or operator position");
        }
    }
    if (result.empty() || want_number) throw std::invalid_argument("incomplete expression");
    return result;
}

namespace {
int priority(char op) { return op == '+' || op == '-' ? 1 : 2; }

int calculate(int left, char op, int right) {
    if (op == '/' && right == 0) throw std::domain_error("division by zero");
    long long answer = 0;
    switch (op) {
        case '+': answer = static_cast<long long>(left) + right; break;
        case '-': answer = static_cast<long long>(left) - right; break;
        case '*': answer = static_cast<long long>(left) * right; break;
        case '/': answer = static_cast<long long>(left) / right; break;
        default: throw std::invalid_argument("unknown operator");
    }
    if (answer < INT_MIN || answer > INT_MAX) throw std::overflow_error("result out of int range");
    return static_cast<int>(answer);
}

void reduce_once(std::vector<int>& numbers, std::vector<char>& operators) {
    if (numbers.size() < 2 || operators.empty()) throw std::invalid_argument("invalid expression");
    int right = numbers.back(); numbers.pop_back();
    int left = numbers.back(); numbers.pop_back();
    char op = operators.back(); operators.pop_back();
    numbers.push_back(calculate(left, op, right));
}
} // namespace

int evaluate_infix(const std::string& text) {
    std::vector<int> numbers;
    std::vector<char> operators;
    for (Token token : tokenize(text)) {
        if (token.kind == 'n') numbers.push_back(token.number);
        else if (token.kind == '(') operators.push_back('(');
        else if (token.kind == ')') {
            while (!operators.empty() && operators.back() != '(') reduce_once(numbers, operators);
            if (operators.empty()) throw std::invalid_argument("unmatched closing parenthesis");
            operators.pop_back();
        } else {
            while (!operators.empty() && operators.back() != '(' &&
                   priority(operators.back()) >= priority(token.kind)) reduce_once(numbers, operators);
            operators.push_back(token.kind);
        }
    }
    while (!operators.empty()) {
        if (operators.back() == '(') throw std::invalid_argument("unmatched opening parenthesis");
        reduce_once(numbers, operators);
    }
    if (numbers.size() != 1) throw std::invalid_argument("invalid expression");
    return numbers.back();
}

std::vector<Token> to_postfix(const std::string& text) {
    std::vector<Token> output;
    std::vector<char> operators;
    for (Token token : tokenize(text)) {
        if (token.kind == 'n') output.push_back(token);
        else if (token.kind == '(') operators.push_back('(');
        else if (token.kind == ')') {
            while (!operators.empty() && operators.back() != '(') {
                output.push_back({operators.back()}); operators.pop_back();
            }
            if (operators.empty()) throw std::invalid_argument("unmatched closing parenthesis");
            operators.pop_back();
        } else {
            while (!operators.empty() && operators.back() != '(' &&
                   priority(operators.back()) >= priority(token.kind)) {
                output.push_back({operators.back()}); operators.pop_back();
            }
            operators.push_back(token.kind);
        }
    }
    while (!operators.empty()) {
        if (operators.back() == '(') throw std::invalid_argument("unmatched opening parenthesis");
        output.push_back({operators.back()}); operators.pop_back();
    }
    return output;
}

int evaluate_postfix(const std::vector<Token>& tokens) {
    std::vector<int> numbers;
    for (Token token : tokens) {
        if (token.kind == 'n') numbers.push_back(token.number);
        else {
            if (numbers.size() < 2) throw std::invalid_argument("invalid postfix expression");
            int right = numbers.back(); numbers.pop_back();
            int left = numbers.back(); numbers.pop_back();
            numbers.push_back(calculate(left, token.kind, right));
        }
    }
    if (numbers.size() != 1) throw std::invalid_argument("invalid postfix expression");
    return numbers.back();
}

std::string show_postfix(const std::vector<Token>& tokens) {
    std::string result;
    for (Token token : tokens) {
        if (!result.empty()) result += ' ';
        result += token.kind == 'n' ? std::to_string(token.number) : std::string(1, token.kind);
    }
    return result;
}

std::string to_prefix(const std::vector<Token>& postfix) {
    std::vector<std::string> parts;
    for (Token token : postfix) {
        if (token.kind == 'n') parts.push_back(std::to_string(token.number));
        else {
            if (parts.size() < 2) throw std::invalid_argument("invalid postfix expression");
            std::string right = parts.back(); parts.pop_back();
            std::string left = parts.back(); parts.pop_back();
            parts.push_back(std::string(1, token.kind) + " " + left + " " + right);
        }
    }
    if (parts.size() != 1) throw std::invalid_argument("invalid postfix expression");
    return parts.back();
}
