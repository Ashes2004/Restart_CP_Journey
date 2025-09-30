#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>


using namespace std;

void bfs(int n, int m, vector<string> grid) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> direction(n, vector<char>(m));

    int sr, sc, er, ec;
    for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j< m ; j++){
            if(grid[i][j] == 'A'){ sr=i; sc=j; }
            if(grid[i][j] == 'B'){ er=i; ec=j; }
        }
    }

    queue<pair<int,int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    int delR[] = {-1, 1, 0, 0};
    int delC[] = {0, 0, -1, 1};
    char delD[] = {'U','D','L','R'};

    bool found = false;

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(row == er && col == ec){
            found = true;
            break;
        }

        for(int i=0; i<4; i++){
            int nr = row + delR[i];
            int nc = col + delC[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && (grid[nr][nc]=='.' || grid[nr][nc]=='B')){
                visited[nr][nc] = true;
                parent[nr][nc] = {row, col};
                direction[nr][nc] = delD[i];
                q.push({nr, nc});
            }
        }
    }

    if(!found){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    string temp;
    int r = er, c = ec;
    while(!(r==sr && c==sc)){
        temp.push_back(direction[r][c]);
        auto p = parent[r][c];
        r = p.first; c = p.second;
    }
    reverse(temp.begin(), temp.end());
    cout << temp.size() << "\n";
    cout << temp << "\n";
}


int main() {
    int n, m;
    cin >> n >> m;

    vector < string > grid(n);

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    
    bfs(n , m , grid);


    return 0;

}
