class Solution {
public:
    void DFS(vector<vector<int>> &grid, int i, int j, char dir, string &hash){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0) 
        return;

        hash += dir;
        grid[i][j] = 0;

        DFS(grid, i+1, j, 'D', hash); 
        DFS(grid, i-1, j, 'U', hash); 
        DFS(grid, i, j+1, 'R', hash); 
        DFS(grid, i, j-1, 'L', hash);

        hash += 'Z';
    }
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        set<string> s;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    string hash;
                    DFS(grid, i, j, 'X', hash);
                    s.insert(hash);
                }
            }
        }
        
        return s.size();
    }
};