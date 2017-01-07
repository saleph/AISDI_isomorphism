#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

class Graph
{
    std::vector<int> vertexes;
    std::vector<std::pair<int*, int*>> edges;
public:
    Graph(std::ifstream file);

    void checkIsomorphism(Graph &other);
};

#endif // GRAPH_H
