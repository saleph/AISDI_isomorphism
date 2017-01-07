#ifndef EDGE_H
#define EDGE_H

class Edge {
    std::pair<int*, int*> edge;
public:
    Edge(int* f, int* s)
        : edge(f, s)
    { }
    bool operator==(const Edge &other) {
        return (*edge.first == *other.edge.first && *edge.second == *other.edge.second) ||
               (*edge.first == *other.edge.second && *edge.second == *other.edge.first);
    }
    bool operator!=(const Edge &other) {
        return !operator==(other);
    }
};

#endif // EDGE_H
