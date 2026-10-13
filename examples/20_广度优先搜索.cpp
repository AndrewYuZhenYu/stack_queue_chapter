#include <iostream>
#include <vector>
#include "applications.h"
#include "interactive.h"

int main() {
    std::cout << "输入无向图，计算指定起点到各顶点的最少边数。顶点编号从 0 开始。\n";
    do {
        int vertices = 0, edges = 0, start = 0;
        if (!read_int_range("顶点数（1–20）：", 1, 20, vertices)) break;
        if (!read_int_range("边数（0–60）：", 0, 60, edges)) break;
        std::vector<std::vector<int>> graph(static_cast<std::size_t>(vertices));
        for (int i = 0; i < edges; ++i) {
            int from = 0, to = 0;
            std::cout << "第 " << i + 1 << " 条边：\n";
            if (!read_int_range("  起点：", 0, vertices - 1, from)) return 0;
            if (!read_int_range("  终点：", 0, vertices - 1, to)) return 0;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        if (!read_int_range("搜索起点：", 0, vertices - 1, start)) break;
        std::vector<int> distances = bfs_distances(graph, start);
        for (std::size_t i = 0; i < distances.size(); ++i) {
            std::cout << start << " 到 " << i << "：";
            if (distances[i] < 0) std::cout << "不可达\n";
            else std::cout << distances[i] << " 条边\n";
        }
    } while (run_again());
}
