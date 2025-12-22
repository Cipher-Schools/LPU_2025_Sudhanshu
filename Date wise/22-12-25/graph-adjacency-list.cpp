/**
 * Program to demonstrate how to make an adjacency list representation of a graph in C++.
 * SC: O(V + E) for space, O(1) for edge addition
 */
#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
public:
    Graph(int V); // Constructor
    void addEdge(int u, int v); // Function to add an edge to the graph
    void printGraph(); // Function to print the adjacency list
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v); // Add v to u's list
    adj[v].push_back(u); // Add u to v's list (for undirected graph)
}

void Graph::printGraph() {
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ":";
        for (int j : adj[i]) {
            cout << " -> " << j;
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