#include <iostream>
#include <string>
#include "graph.h"
using namespace std;
int main(void) {
    Graph g;

    string filename;
    getline(cin, filename);

    g.LoadMatrix(filename);
    int n = g.GetSize();
    for (int i = 0; i < n; i++) {
        g.PrintShortestPathWeight(i);
    }
    return 0;
}