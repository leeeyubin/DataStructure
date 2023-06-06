#include "graph.h"
void Graph::LoadMatrix(std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "파일을 여는 데 실패했습니다." << std::endl;
        return;
    }

    int size;
    inputFile >> size;

    adjacencyMatrix.resize(size, std::vector<int>(size));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    inputFile.close();
}
int Graph::GetSize() {
    return adjacencyMatrix.size();
}
void Graph::PrintMatrix() {
    int size = adjacencyMatrix.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (adjacencyMatrix[i][j] == 999) {
                std::cout << "999 ";
            }
            else {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}
void Graph::PrintShortestPathWeight(int s) {
    int size = adjacencyMatrix.size();
    std::vector<int> dist(size, 999);
    std::vector<bool> visited(size, false);
    dist[s] = 0;
    for (int count = 0; count < size - 1; ++count) {
        int minDist = 999;
        int minIndex = -1;
        for (int i = 0; i < size; ++i) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        if (minIndex == -1) {
            break; 
        }
        visited[minIndex] = true;
        for (int i = 0; i < size; ++i) {
            if (!visited[i] && adjacencyMatrix[minIndex][i] != 999 &&
                dist[minIndex] + adjacencyMatrix[minIndex][i] < dist[i]) {
                dist[i] = dist[minIndex] + adjacencyMatrix[minIndex][i];
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        if (dist[i] == 999) {
            std::cout << "999" << std::endl;
        }
        else {
            std::cout << dist[i] << std::endl;
        }
    }
}