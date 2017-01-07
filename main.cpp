#include <iostream>
#include "graph.h"

int main(int argc, char *argv[])
{
    Graph g1(std::ifstream("graf1.txt"));
    Graph g2(std::ifstream("graf2.txt"));
    g1.checkIsomorphism(g2);
    return 0;
}
