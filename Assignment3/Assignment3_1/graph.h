#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
class Graph {
private:
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    void LoadMatrix(std::string& filename);
    void PrintMatrix();
};
#endif
