class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }
        
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!q.empty()){
            pair<int, int> curr= q.front();
            q.pop();
            int i = curr.first; int j = curr.second; int dist = mat[i][j];
            
            for(int k = 0; k < 4; k++){
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(x < 0 || y < 0 || x == n || y == m || mat[x][y] != -1)
                    continue;
                mat[x][y] = dist + 1;
                q.push({x, y});
            }
        }
        return mat;
    }
};

//OR

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int visited[n][m];
        memset(visited, 0, sizeof(visited));
        queue<vector<int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j, 0});
                    visited[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()){
            vector<int> curr = q.front();
            int i = curr[0]; int j = curr[1]; int dist = curr[2];
            q.pop();
            
            if(i+1 <= n-1 && !visited[i+1][j]){
                mat[i+1][j] = dist + 1;
                visited[i+1][j] = 1;
                q.push({i+1, j, dist+1});
            }
            
            if(i-1 >= 0 && !visited[i-1][j]){
                mat[i-1][j] = dist + 1;
                visited[i-1][j] = 1;
                q.push({i-1, j, dist+1});
            }
            
            if(j+1 <= m-1 && !visited[i][j+1]){
                mat[i][j+1] = dist + 1;
                visited[i][j+1] = 1;
                q.push({i, j+1, dist+1});
            }
            
            if(j-1 >= 0 && !visited[i][j-1]){
                mat[i][j-1] = dist + 1;
                visited[i][j-1] = 1;
                q.push({i, j-1, dist+1});
            }
        }
        return mat;
    }
};