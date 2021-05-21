class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j])
                    q.push({i, j});
                
        if(q.size() == 0 || q.size() == n*n)
            return -1;
        
        int level = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                pair<int, int> curr = q.front();
                int i = curr.first;
                int j = curr.second;
                q.pop();
                
                for(int k = 0; k < 4; k++){
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    
                    if(x < 0 || y < 0 || x == n || y == n || grid[x][y] == 1)
                        continue;
                    
                    q.push({x, y});
                    grid[x][y] = 1;
                }
                size--;
            }
            level++;
        }
        
        return level - 1;
    }
};