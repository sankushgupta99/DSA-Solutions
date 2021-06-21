class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;
        int n = grid.size();
        
        int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            int time = curr[0];
            int i = curr[1];
            int j = curr[2];
            
            if(i == n-1 && j == n-1)
                return time;
            
            for(int k = 0; k < 4; k++){
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                
                if(x < 0 || y < 0 || x == n || y == n || grid[x][y] == -1)
                    continue;
                
                if(x == n-1 && y == n-1)
                    return max(time, grid[x][y]);
                
                pq.push({max(time, grid[x][y]), x, y});
                grid[x][y] = -1;
            }
        }
        return -1;
    }
};