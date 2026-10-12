#include <iostream>
#include <vector>
#include "算法应用.h"

int main() {
    const std::vector<std::vector<int>> graph{{1, 2}, {0, 3}, {0, 3, 4},
                                               {1, 2, 5}, {2, 5}, {3, 4}};
    std::vector<int> distances = bfs_distances(graph, 0);
    for (std::size_t i = 0; i < distances.size(); ++i)
        std::cout << "0 到 " << i << " 的最少边数=" << distances[i] << '\n';
}
