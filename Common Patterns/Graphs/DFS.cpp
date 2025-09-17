#include<bits/stdc++.h>
using namespace std;


void dfsTrav(int start , vector<vector<int>>&adj , int n , vector<bool>&visited)
{
    visited[start] = true;
    cout<<start<<" ";
    for(int node : adj[start])
    {
        if(!visited[node])
        {
            dfsTrav(node , adj , n , visited);
        }
    }
}

void dfs(int start , vector<vector<int>>&adj , int n)
{
    vector<bool>visited(n , false);
    dfsTrav(start , adj , n , visited);
}



int main() {
    int n = 6; 
    vector<vector<int>> adj(n);

   
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    cout << "BFS starting from node 0: ";
    dfs(0, adj, n);
    return 0;
}