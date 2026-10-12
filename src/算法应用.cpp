#include "算法应用.h"

#include "栈.h"
#include "队列.h"

#include <array>
#include <cstdlib>
#include <ostream>
#include <stdexcept>
#include <utility>

namespace {
void enumerate(int next, int n, GrowingStack& stack, std::vector<int>& output,
               std::string& actions, std::vector<StackSequence>& results) {
    if (static_cast<int>(output.size()) == n) {
        results.push_back({output, actions});
        return;
    }
    if (next <= n) {
        stack.push(next);
        actions += 'S';
        enumerate(next + 1, n, stack, output, actions, results);
        actions.pop_back();
        stack.pop();
    }
    if (!stack.empty()) {
        int value = *stack.pop();
        output.push_back(value);
        actions += 'X';
        enumerate(next, n, stack, output, actions, results);
        actions.pop_back();
        output.pop_back();
        stack.push(value);
    }
}

bool safe_queen(const std::vector<int>& columns, int row, int col) {
    for (int old_row = 0; old_row < row; ++old_row)
        if (columns[old_row] == col ||
            std::abs(columns[old_row] - col) == row - old_row) return false;
    return true;
}
void search_queens(std::vector<int>& columns, int row,
                   std::vector<std::vector<int>>& solutions) {
    int n = static_cast<int>(columns.size());
    if (row == n) { solutions.push_back(columns); return; }
    for (int col = 0; col < n; ++col) {
        if (!safe_queen(columns, row, col)) continue;
        columns[row] = col;
        search_queens(columns, row + 1, solutions);
        columns[row] = -1;
    }
}
} // namespace

std::vector<StackSequence> stack_sequences(int n) {
    if (n < 0 || n > 10) throw std::invalid_argument("n must be 0..10");
    GrowingStack stack;
    std::vector<int> output;
    std::string actions;
    std::vector<StackSequence> results;
    enumerate(1, n, stack, output, actions, results);
    return results;
}

std::string convert_base(int number, int base) {
    if (base < 2 || base > 16) throw std::invalid_argument("base must be 2..16");
    if (number == 0) return "0";
    constexpr char digits[] = "0123456789ABCDEF";
    bool negative = number < 0;
    long long magnitude = negative ? -static_cast<long long>(number) : number;
    GrowingStack stack;
    while (magnitude != 0) {
        stack.push(static_cast<int>(magnitude % base));
        magnitude /= base;
    }
    std::string result = negative ? "-" : "";
    while (auto digit = stack.pop()) result += digits[*digit];
    return result;
}

bool brackets_match(const std::string& text) {
    std::vector<char> openings;
    for (char ch : text) {
        if (ch == '(' || ch == '[' || ch == '{') openings.push_back(ch);
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (openings.empty()) return false;
            char left = openings.back();
            openings.pop_back();
            if ((ch == ')' && left != '(') || (ch == ']' && left != '[') ||
                (ch == '}' && left != '{')) return false;
        }
    }
    return openings.empty();
}

std::string edit_line(const std::string& input) {
    std::string buffer;
    for (char ch : input) {
        if (ch == '#') { if (!buffer.empty()) buffer.pop_back(); }
        else if (ch == '@') buffer.clear();
        else buffer.push_back(ch);
    }
    return buffer;
}

std::vector<Point> find_maze_path(const std::vector<std::string>& maze,
                                  Point start, Point goal) {
    if (maze.empty() || maze[0].empty()) throw std::invalid_argument("empty maze");
    std::size_t width = maze[0].size();
    for (const std::string& row : maze)
        if (row.size() != width) throw std::invalid_argument("maze must be rectangular");
    auto valid = [&](Point p) {
        return p.row >= 0 && p.col >= 0 &&
               p.row < static_cast<int>(maze.size()) && p.col < static_cast<int>(width) &&
               maze[p.row][p.col] != '#';
    };
    if (!valid(start) || !valid(goal)) throw std::invalid_argument("invalid start or goal");
    struct Frame { Point point; int next_direction; };
    const std::array<Point, 4> directions{{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(width, false));
    std::vector<Frame> stack{{start, 0}};
    visited[start.row][start.col] = true;
    while (!stack.empty()) {
        Frame& frame = stack.back();
        if (frame.point.row == goal.row && frame.point.col == goal.col) {
            std::vector<Point> path;
            for (const Frame& item : stack) path.push_back(item.point);
            return path;
        }
        if (frame.next_direction == 4) { stack.pop_back(); continue; }
        Point step = directions[frame.next_direction++];
        Point next{frame.point.row + step.row, frame.point.col + step.col};
        if (valid(next) && !visited[next.row][next.col]) {
            visited[next.row][next.col] = true;
            stack.push_back({next, 0});
        }
    }
    return {};
}

int trace_factorial(int n, int depth, std::ostream& output) {
    if (n < 0 || n > 12) throw std::invalid_argument("n must be 0..12");
    output << std::string(depth * 2, ' ') << "进入 factorial(" << n << ")\n";
    int answer = n <= 1 ? 1 : n * trace_factorial(n - 1, depth + 1, output);
    output << std::string(depth * 2, ' ') << "返回 " << answer << '\n';
    return answer;
}

void hanoi_moves(int n, char from, char via, char to, std::ostream& output) {
    if (n < 0 || n > 20) throw std::invalid_argument("n must be 0..20");
    if (n == 0) return;
    hanoi_moves(n - 1, from, to, via, output);
    output << "圆盘 " << n << ": " << from << " -> " << to << '\n';
    hanoi_moves(n - 1, via, from, to, output);
}

std::vector<std::vector<int>> solve_n_queens(int n) {
    if (n < 1 || n > 12) throw std::invalid_argument("n must be 1..12");
    std::vector<int> columns(static_cast<std::size_t>(n), -1);
    std::vector<std::vector<int>> solutions;
    search_queens(columns, 0, solutions);
    return solutions;
}

std::vector<int> bfs_distances(const std::vector<std::vector<int>>& graph, int start) {
    if (start < 0 || start >= static_cast<int>(graph.size()))
        throw std::invalid_argument("invalid start vertex");
    std::vector<int> distance(graph.size(), -1);
    CircularQueue queue(graph.size());
    distance[start] = 0;
    queue.enqueue(start);
    while (auto current = queue.dequeue()) {
        for (int neighbor : graph[*current]) {
            if (neighbor < 0 || neighbor >= static_cast<int>(graph.size()))
                throw std::invalid_argument("invalid graph edge");
            if (distance[neighbor] != -1) continue;
            distance[neighbor] = distance[*current] + 1;
            queue.enqueue(neighbor);
        }
    }
    return distance;
}

void recursive_print(int n, std::ostream& output) {
    if (n <= 1) return;
    output << n;
    recursive_print(n - 1, output);
}
void iterative_print(int n, std::ostream& output) {
    for (int i = n; i > 1; --i) output << i;
}
void recursive_unwind_sum(const std::vector<int>& input, std::size_t index,
                          int& sum, std::ostream& output) {
    if (index == input.size() || input[index] == 0) sum = 0;
    else {
        recursive_unwind_sum(input, index + 1, sum, output);
        sum += input[index];
    }
    output << sum << ' ';
}
void iterative_unwind_sum(const std::vector<int>& input, std::ostream& output) {
    GrowingStack frames;
    for (int value : input) {
        if (value == 0) break;
        frames.push(value);
    }
    int sum = 0;
    output << sum << ' ';
    while (auto value = frames.pop()) {
        sum += *value;
        output << sum << ' ';
    }
}

KStepResult k_step_fibonacci(int k, int maximum) {
    if (k < 2 || maximum < 1) throw std::invalid_argument("k >= 2 and max >= 1 required");
    CountingQueue window(static_cast<std::size_t>(k));
    std::vector<int> terms;
    for (int i = 0; i < k - 1; ++i) { window.enqueue(0); terms.push_back(0); }
    window.enqueue(1);
    terms.push_back(1);
    long long next = 1;
    while (next <= maximum) {
        int value = static_cast<int>(next);
        int oldest = *window.dequeue();
        window.enqueue(value);
        terms.push_back(value);
        next += static_cast<long long>(value) - oldest;
    }
    return {terms, window.front_to_rear(), next};
}
