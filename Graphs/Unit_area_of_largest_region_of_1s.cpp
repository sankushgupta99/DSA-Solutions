class Solution
{
    public:
    void DFS(vector<vector<int>> &grid, int i, int j, int &curr_area){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || !grid[i][j])
        return;
        
        curr_area++;
        grid[i][j] = 0;
        
        DFS(grid, i-1, j, curr_area); DFS(grid, i+1, j, curr_area);
        DFS(grid, i, j-1, curr_area); DFS(grid, i, j+1, curr_area);
        DFS(grid, i-1, j-1, curr_area); DFS(grid, i-1, j+1, curr_area);
        DFS(grid, i+1, j-1, curr_area); DFS(grid, i+1, j+1, curr_area);
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int max_area = 0; 
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                
                if(grid[i][j] == 1){
                    int curr_area = 0;
                    DFS(grid, i, j, curr_area);
                    max_area = max(max_area, curr_area);
                }
                
            }
        }
        return max_area;
    }
};