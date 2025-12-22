/**
 * Program to demonstrate dfs traversal in a graph using C++14.
 * TC: O(V + E) where V is number of vertices and E is number of edges.
 * SC: O(V) for visited array and recursion stack.
 */

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list representation
public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFSUtil(int v, vector<bool>& visited);
    void DFS(int start);
};
Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // For undirected graph
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited);
        }
    }
}
void Graph::DFS(int start) {
    vector<bool> visited(V, false);
    DFSUtil(start, visited);
}
int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    cout << "Depth First Traversal starting from vertex 0:\n";
    g.DFS(0);

    return 0;
}
