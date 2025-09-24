#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void dijkstra(int n, int src, vector<vector<pair<int,int>>> &adj) {
    vector<int> dist(n+1, INF);  
    dist[src] = 0;

    // min-heap: {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first; // distance
        int u = pq.top().second; // node
        pq.pop();

        if (d > dist[u]) continue; // skip outdated pair

        // for-each loop (without structured binding)
        for (pair<int,int> edge : adj[u]) {
            int v = edge.first;  // neighbour node
            int w = edge.second; // weight

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n, m;
    cin >> n >> m; // number of nodes, edges

    vector<vector<pair<int,int>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;  // edge u -> v with weight w
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this if graph is directed
    }

    int src;
    cin >> src;

    dijkstra(n, src, adj);

    return 0;
}
