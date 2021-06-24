#define mod 1000000007
class Solution {
public:
    int dp[51][51][51];
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int countPaths(int m, int n, int i, int j, int k){
        if(i < 0 || j < 0 || i == m || j == n)
            return 1;
        if(k == 0)
            return 0;
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        dp[i][j][k] = 0;
        for(int it = 0; it < 4; it++){
            int x = i + dir[it][0];
            int y = j + dir[it][1];
            
            dp[i][j][k] = (dp[i][j][k] + countPaths(m, n, x, y, k-1)) % mod;
        }
        
        return dp[i][j][k];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return countPaths(m, n, startRow, startColumn, maxMove);
    }
};