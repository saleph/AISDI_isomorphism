#include "graph.h"

Graph::Graph(std::ifstream file) {
    {
        int vertexNo;
        file >> vertexNo;
        for (int i = 0; i < vertexNo; ++i)
            vertexes.push_back(i);
    }

    while (file.good()) {
        int first, second;
        file >> first;
        file >> second;
        if (first <= second)
            edges.emplace_back(&vertexes[first], &vertexes[second]);
        else
            edges.emplace_back(&vertexes[second], &vertexes[first]);
    }
}

void Graph::checkIsomorphism(Graph &other) {
    if (vertexes.size() != other.vertexes.size() ||
            edges.size() != other.edges.size()) {
        std::cout << "Nieizomorficzne\n";
        return;
    }
    for (;;) {
        bool thesame = true;
        for (auto& e1 : edges) {
            for (auto& e2 : other.edges) {
                if ((*e1.first != *e2.first  && *e1.second != *e2.second) &&
                    (*e1.first != *e2.second && *e1.second != *e2.first)) {
                    thesame = false;
                    break;
                }
            }
            if (!thesame)
                break;
        }
        if (thesame) {
            std::cout << "Izomorficzne!\n";
            std::cout << other.vertexes.size();
            for (int i=0; i<other.vertexes.size(); ++i) {
                std::cout << i << " ---> " << other.vertexes[i] << '\n';
            }
            return;
        }
        if(!std::next_permutation(other.vertexes.begin(), other.vertexes.end())) {
            std::cout << "Nieizomorficzne\n";
            return;
        }
    }
}
