#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src) {
    vector<int> dist(V, 1e9); 
    dist[src] = 0;

    // Relax all edges (V-1) times
    for (int i = 1; i <= V - 1; i++) {
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            cout << "Negative weight cycle detected\n";
            return {};
        }
    }

    return dist;
}


/*Why relax V−1 times?

1. A shortest path in a graph with V vertices can have at most (V−1) edges.
Think: if you have 5 nodes, the longest simple path (without repeating nodes) can only have 4 edges.
If you try to go through 5 or more edges, you must revisit some node → that forms a cycle.

2. Relaxation means:
For an edge (u → v) with weight w:
if dist[u] + w < dist[v], then update dist[v].

3. Each relaxation step ensures we find the shortest paths using that many edges:
1st iteration: shortest paths that use ≤ 1 edge.
2nd iteration: shortest paths that use ≤ 2 edges.

…

(V−1)th iteration: shortest paths that use ≤ (V−1) edges.

4. After (V−1) iterations → all possible shortest paths are found.
If we do one more iteration and something still improves → it means there’s a negative cycle*/

int main() {
    int V = 5; 
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };

    int src = 0;
    vector<int> dist = bellmanFord(V, edges, src);

    if (!dist.empty()) {
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " -> " << dist[i] << "\n";
        }
    }

    return 0;
}
