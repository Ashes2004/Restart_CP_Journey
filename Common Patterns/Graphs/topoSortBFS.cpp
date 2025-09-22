#include <bits/stdc++.h>
using namespace std;

// the point is if we have u -> v edge then u always comes before v here we use indgree means number of incoming edges to that particular nodes


    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }



int main() {
    int V, E;
    cin >> V >> E; 

   
    vector<vector<int>> edges(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }


    vector<int> result = topoSort(V, adj);

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


