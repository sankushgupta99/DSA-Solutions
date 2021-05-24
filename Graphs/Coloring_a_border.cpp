class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0,-1}};
    int visited[100][100];
    
    void DFS(vector<vector<int>> &grid, int i, int j, int color, int org_color){
        visited[i][j] = 1;
        int count = 0;
        
        for(int k = 0; k < 4; k++){
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            
            if(x < 0 || y < 0 || x == grid.size() || y == grid[0].size())
                continue;
            else if(visited[x][y])
                count++;
            else if(grid[x][y] == org_color){
                count++;
                DFS(grid, x, y, color, org_color);
            }
        }
        
        if(count != 4)
            grid[i][j] = color;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int org_color = grid[r0][c0];
        
        if(color == org_color)
            return grid;
        
        memset(visited, 0, sizeof(visited));
        
        DFS(grid, r0, c0, color, org_color);
        
        return grid;
    }
};