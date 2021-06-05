class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void BFS(vector<vector<int>> grid, int i, int j, int &dist, int &count){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 2;
        int level = 1;

        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                pair<int, int> curr = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int x = curr.first + dir[k][0];
                    int y = curr.second + dir[k][1];

                    if(x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] == 2)
                    continue;

                    if(grid[x][y] == 1){
                        dist += level;
                        count++;
                    }
                    if(grid[x][y] == 0)
                        q.push({x,y});
                    
                    grid[x][y] = 2;
                }
                size--;
            }
            level++;
        }
    }

    int shortestDistance(vector<vector<int>> &grid) {
        int min_dist = INT_MAX;
        int building_count = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    building_count++;
                }
            }
        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    int dist = 0, count = 0;
                    BFS(grid, i, j, dist, count);

                    if(count == building_count && dist < min_dist)
                    min_dist = dist;
                }
            }
        }

        return min_dist;
    }
};