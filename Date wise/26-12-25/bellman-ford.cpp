/**
 * program to implement Bellman-Ford algorithm to find the shortest path
 * from a source vertex to all other vertices in a weighted graph.
 * TC: O(VE), SC: O(V)
 */

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
    int V, E;
    vector<Edge> edges;
public:
    Graph(int V, int E) : V(V), E(E) {
        edges.reserve(E);
    }
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void bellmanFord(int src) {
        vector<int> dist(V, numeric_limits<int>::max());
        dist[src] = 0;

        for (int i = 1; i <= V - 1; i++) {
            for (const auto& edge : edges) {
                int u = edge.src;
                int v = edge.dest;
                int weight = edge.weight;
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }

        cout << "Vertex Distance from Source (" << src << "):" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << "\t\t" << dist[i] << endl;
        }
    }
};

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    Graph g(V, E);

    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.bellmanFord(0);

    return 0;
}