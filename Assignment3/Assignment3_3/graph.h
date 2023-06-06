#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
class Graph {
private:
    std::vector<std::vector<int>> adjacencyMatrix;
    int size;

public:
    void LoadMatrix(std::string& filename);
    int GetSize();
    void PrintMatrix();
    void PrintShortestPathWeight(int s);
    void PrintShortestPath(int s);
};

#endif