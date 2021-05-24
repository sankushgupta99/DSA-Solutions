class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q;
        int fresh = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        if(fresh == 0)
        return 0;
        
        int level = 0;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for(int k = 0; k < 4; k++){
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    
                    if(x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] != 1)
                    continue;
                    
                    grid[x][y] = 2;
                    fresh--;
                    q.push({x, y});
                }
                size--;
            }
            level++;
        }
        
        if(fresh)
        return -1;
        
        return level - 1;
    }
};

//OR

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 2)
                    q.push({i, j});
        
        int time = 0;
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for(int k = 0; k < 4; k++){
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    
                    if(x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] != 1)
                        continue;
                    
                    q.push({x, y});
                    grid[x][y] = 2;
                }
                size--;
            }
            time++;
        }
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1)
                    return -1;
        
         return max(0, time - 1);
    }
};