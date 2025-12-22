/**
 * Program to demonstrate how to represent a graph using an adjacency matrix in C++.
 * SC: O(V^2) for space, O(1) for edge addition and lookup
 */
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjMatrix; // Adjacency matrix
public:
    Graph(int V); // Constructor
    void addEdge(int u, int v); // Function to add an edge to the graph
    void printGraph(); // Function to print the adjacency matrix
};

Graph::Graph(int V) {
    this->V = V;
    adjMatrix.resize(V, vector<int>(V, 0)); // Initialize VxV matrix with 0s
}
void Graph::addEdge(int u, int v) {
    adjMatrix[u][v] = 1; // Add edge from u to v
    adjMatrix[v][u] = 1; // Add edge from v to u (for undirected graph)
}
void Graph::printGraph() {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int V = 5; // Number of vertices
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}