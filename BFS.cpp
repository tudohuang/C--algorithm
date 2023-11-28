#include <iostream>
#include <list>
#include <queue>

class Graph {
    int numVertices;
    std::list<int> *adjLists;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
}

void Graph::BFS(int startVertex) {
    std::vector<bool> visited(numVertices, false);
    std::queue<int> queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        int currVertex = queue.front();
        std::cout << "Visited " << currVertex << " ";
        queue.pop();

        for (int adjVertex : adjLists[currVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.BFS(0);
    return 0;
}
