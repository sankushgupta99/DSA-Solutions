class Solution {
public:
    void DFS(int m, int n, vector<vector<int>> &grid, int i, int j){
        if(i < 0 || j < 0 || i == m || j == n || !grid[i][j])
            return;
        grid[i][j] = 0;
        DFS(m, n, grid, i+1, j); DFS(m, n, grid, i-1, j); 
        DFS(m, n, grid, i, j+1); DFS(m, n, grid, i, j-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(i*j == 0 || i == m-1 || j == n-1)
                    DFS(m, n, grid, i, j);
        int ans = 0;
        for(auto i : grid)
            for(auto j : i)
                if(j == 1) 
                  ans++;
            
        return ans;
    }
};

//OR

class Solution {
public:
    void DFS(int m, int n, vector<vector<int>> &grid, int i, int j){
        grid[i][j] = 0;
        if(i+1 <= m-1 && grid[i+1][j])
            DFS(m, n, grid, i+1, j);
        
        if(i-1 >= 0 && grid[i-1][j])
            DFS(m, n, grid, i-1, j);
        
        if(j+1 <= n-1 && grid[i][j+1])
            DFS(m, n, grid, i, j+1);
        
        if(j-1 >= 0 && grid[i][j-1])
            DFS(m, n, grid, i, j-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++)
            if(grid[i][0] == 1)
                DFS(m, n, grid, i, 0);
        
        for(int i = 1; i < n; i++)
            if(grid[m-1][i] == 1)
                DFS(m, n, grid, m-1, i);
        
        for(int i = m - 2; i >= 0; i--)
            if(grid[i][n-1] == 1)
                DFS(m, n, grid, i, n-1);
        
        for(int i = n - 2; i >= 1; i--)
            if(grid[0][i] == 1)
                DFS(m, n, grid, 0, i);
        
        int ans = 0;
        for(auto i : grid){
            for(auto j : i){
                if(j == 1)
                    ans++;
            }
        }
        return ans;
    }
};