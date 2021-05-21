class Solution {
public:
    void DFS(vector<vector<int>> &grid, int i, int j, queue<pair<int, int>> &q){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1){
            return;
        }
        
        q.push({i, j});
        grid[i][j] = 2;
        
        DFS(grid, i+1, j, q); DFS(grid, i-1, j, q); DFS(grid, i, j+1, q); DFS(grid, i, j-1, q);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q;
        int flag = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    DFS(grid, i, j, q);
                    flag++;
                    break;
                }
            }
            if(flag)
            break;
        }
        
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                pair<int, int> curr = q.front();
                int x = curr.first;
                int y = curr.second;
                q.pop();
                
                for(int k = 0; k < 4; k++){
                    int i = x + dir[k][0];
                    int j = y + dir[k][1];
                    
                    if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 2)
                        continue;
                    
                    if(grid[i][j] == 1)
                        return level;
                    
                    q.push({i, j});
                    grid[i][j] = 2;
                }
                size--;
            }
            level++;
        }
        return -1;
    }
};