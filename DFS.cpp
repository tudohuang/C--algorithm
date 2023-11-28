#include <iostream>
#include <list>
#include <vector>

class Graph {
    int numVertices;
    std::list<int> *adjLists;
    void DFSUtil(int v, std::vector<bool>& visited);

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void DFS(int startVertex);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
}

void Graph::DFSUtil(int v, std::vector<bool>& visited) {
    visited[v] = true;
    std::cout << v << " ";
    for (int i : adjLists[v]) {
        if (!visited[i])
            DFSUtil(i, visited);
    }
}

void Graph::DFS(int startVertex) {
    std::vector<bool> visited(numVertices, false);
    DFSUtil(startVertex, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.DFS(0);
    return 0;
}
