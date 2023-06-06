#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
void Graph::LoadMatrix(std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        adjacencyMatrix.resize(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file >> adjacencyMatrix[i][j];
            }
        }
        file.close();
    }
    else {
        std::cout << "파일을 여는 데에 실패했습니다." << std::endl;
    }
}
int Graph::GetSize() {
    return size;
}
void Graph::PrintMatrix() {
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            if (val == 999) {
                std::cout << "999 ";
            }
            else {
                std::cout << val << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Graph::PrintShortestPathWeight(int s) {
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

void Graph::PrintShortestPath(int s) {
    std::vector<int> dist(size, 999);
    std::vector<int> prev(size, -1);
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
                prev[i] = minIndex;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        if (i == s) {
            continue;
        }

        std::vector<int> path;
        int current = i;
        while (current != -1) {
            path.push_back(current);
            current = prev[current];
        }

        for (int j = path.size() - 1; j >= 0; --j) {
            std::cout << path[j] << " ";
        }
        std::cout << std::endl;
    }
}