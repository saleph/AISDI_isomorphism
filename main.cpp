#include <iostream>
#include "graph.h"

int main(int argc, char *argv[])
{
    Graph g1{std::ifstream(argv[1])};
    Graph g2{std::ifstream(argv[2])};

    g1.checkIsomorphism(g2);
    return 0;
}
