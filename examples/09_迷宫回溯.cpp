#include <iostream>
#include <string>
#include <vector>
#include "applications.h"

int main() {
    const std::vector<std::string> maze{
        "########", "#S #   #", "#  # # #", "##   #E#", "########"
    };
    std::vector<Point> path = find_maze_path(maze, {1, 1}, {3, 6});
    std::cout << (path.empty() ? "无路径" : "找到路径：") << '\n';
    for (Point point : path) std::cout << '(' << point.row << ',' << point.col << ") ";
    std::cout << '\n';
}
