#pragma once

#include <cstddef>
#include <iosfwd>
#include <string>
#include <vector>

struct StackSequence {
    std::vector<int> output;
    std::string actions;
};
std::vector<StackSequence> stack_sequences(int n);
std::string convert_base(int number, int base);
bool brackets_match(const std::string& text);
std::string edit_line(const std::string& input);

struct Point { int row; int col; };
std::vector<Point> find_maze_path(const std::vector<std::string>& maze, Point start, Point goal);

int trace_factorial(int n, int depth, std::ostream& output);
void hanoi_moves(int n, char from, char via, char to, std::ostream& output);
std::vector<std::vector<int>> solve_n_queens(int n);
std::vector<int> bfs_distances(const std::vector<std::vector<int>>& graph, int start);
void recursive_print(int n, std::ostream& output);
void iterative_print(int n, std::ostream& output);
void recursive_unwind_sum(const std::vector<int>& input, std::size_t index,
                          int& sum, std::ostream& output);
void iterative_unwind_sum(const std::vector<int>& input, std::ostream& output);

struct KStepResult {
    std::vector<int> terms;
    std::vector<int> window;
    long long next;
};
KStepResult k_step_fibonacci(int k, int maximum);
