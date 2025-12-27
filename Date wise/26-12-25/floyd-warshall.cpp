/**
 * Program to implement the Floyd-Warshall algorithm for finding shortest paths
 * between all pairs of vertices in a weighted graph.
 * Handles negative weights but no negative cycles.
 * TC: O(V^3), SC: O(V^2)
 */

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> dist;
public:
    Graph(int V) : V(V), dist(V, vector<int>(V, numeric_limits<int>::max())) {
        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }
    }
    void addEdge(int u, int v, int w) {
        dist[u][v] = w;
    }
    void floydWarshall() {
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != numeric_limits<int>::max() && dist[k][j] != numeric_limits<int>::max() &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        cout << "Shortest distances between every pair of vertices:" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == numeric_limits<int>::max()) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int V = 4; // Number of vertices
    Graph g(V);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, -2);

    g.floydWarshall();

    return 0;
}