class Solution
{
    public:
    void DFS(vector<vector<int>> &grid, int i, int j, bool &isPath){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0)
        return;
        
        if(grid[i][j] == 2)
        {
            isPath = true;
            return;
        }
        
        grid[i][j] = 0;
        DFS(grid, i+1, j, isPath); DFS(grid, i-1, j, isPath);
        DFS(grid, i, j+1, isPath); DFS(grid, i, j-1, isPath);
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        bool isPath = false;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    DFS(grid, i, j, isPath);
                }
            }
        }
        return isPath;
    }
};