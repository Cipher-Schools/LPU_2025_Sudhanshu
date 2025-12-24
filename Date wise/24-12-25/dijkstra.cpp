/**
 * Program to demo Dijkstra's shortest path algorithm on a weighted graph using C++.
 * The graph is represented using an adjacency list.
 * This implementation uses a priority queue to efficiently get the next node with the smallest distance.
 * SC: O((V + E) log V) where V is the number of vertices and E is the number of edges.
 * TC: O((V + E) log V)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max();
typedef pair<int, int> pii; // Pair to represent (distance, vertex)
class Graph {
    int V; // Number of vertices
    vector<vector<pii>> adj; // Adjacency list representation
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    vector<int> dijkstra(int src);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].emplace_back(w, v); // Add edge u -> v with weight w
    adj[v].emplace_back(w, u); // For undirected graph, add edge v -> u
}

vector<int> Graph::dijkstra(int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap priority queue
    pq.emplace(0, src); // (distance, vertex)

    while (!pq.empty()) {
        int u = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        // If the distance is greater than the recorded distance, skip processing
        if (currDist <= dist[u]){
            for (const auto& neighbor : adj[u]) {
                int weight = neighbor.first;
                int v = neighbor.second;
    
                // Relaxation step
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                }
            }
        }

    }
    return dist;
}

int main() {
    int V = 5; // Number of vertices
    Graph g(V);

    // Adding edges: g.addEdge(u, v, weight);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 7);
    g.addEdge(4, 3, 9);

    int source = 0;
    vector<int> distances = g.dijkstra(source);

    cout << "Vertex Distance from Source (" << source << "):\n";
    for (int i = 0; i < V; ++i) {
        if (distances[i] == INF) {
            cout << "Vertex " << i << ": INF\n";
        } else {
            cout << "Vertex " << i << ": " << distances[i] << "\n";
        }
    }

    return 0;
}