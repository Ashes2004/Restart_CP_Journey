#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int row, int col, vector<string>& grid, vector<vector<bool>>& visited) {
    visited[row][col] = true;
    int m = grid.size();
    int n = grid[0].size();
    
    int delR[] = {-1, 0, 1, 0};
    int delC[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nr = row + delR[i];
        int nc = col + delC[i];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n 
            && !visited[nr][nc] && grid[nr][nc] == '.') {
            dfs(nr, nc, grid, visited);
        }
    }
}

int main() {  
    int m, n;
    cin >> m >> n;
    vector<string> grid(m);

    for (int i = 0; i < m; i++) {
        cin >> grid[i];  
    }

    int count = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {   
            if (!visited[i][j] && grid[i][j] == '.') {
                dfs(i, j, grid, visited);
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
