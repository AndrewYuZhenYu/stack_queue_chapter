#include <iostream>
#include <string>
#include <vector>
#include "applications.h"
#include "interactive.h"

int main() {
    std::cout << "自定义迷宫：# 是墙，. 是通路，S 是入口，E 是出口。\n";
    do {
        int rows = 0, cols = 0;
        if (!read_int_range("行数（2–20）：", 2, 20, rows)) break;
        if (!read_int_range("列数（2–20）：", 2, 20, cols)) break;
        std::vector<std::string> maze;
        Point start{-1, -1}, goal{-1, -1};
        int start_count = 0, goal_count = 0;
        for (int row = 0; row < rows; ++row) {
            std::string line;
            while (true) {
                if (!read_line("第 " + std::to_string(row + 1) + " 行：", line)) return 0;
                bool valid = static_cast<int>(line.size()) == cols &&
                             line.find_first_not_of("#.SE") == std::string::npos;
                if (valid) break;
                std::cout << "这一行必须恰好有 " << cols << " 个 #、.、S 或 E。\n";
            }
            for (int col = 0; col < cols; ++col) {
                if (line[col] == 'S') {
                    ++start_count;
                    start = {row, col};
                }
                if (line[col] == 'E') {
                    ++goal_count;
                    goal = {row, col};
                }
            }
            maze.push_back(line);
        }
        if (start_count != 1 || goal_count != 1) {
            std::cout << "需要恰好一个 S 和一个 E，请重新输入迷宫。\n";
            continue;
        }
        std::vector<Point> path = find_maze_path(maze, start, goal);
        if (path.empty()) std::cout << "没有从 S 到 E 的路径。\n";
        else {
            for (Point point : path)
                if (maze[point.row][point.col] == '.') maze[point.row][point.col] = '*';
            std::cout << "找到路径，* 表示经过的通路：\n";
            for (const std::string& line : maze) std::cout << line << '\n';
            std::cout << "路径长度（步数）=" << path.size() - 1 << '\n';
        }
    } while (run_again());
}
