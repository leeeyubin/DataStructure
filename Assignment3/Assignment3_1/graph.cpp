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
