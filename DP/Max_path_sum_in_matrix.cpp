class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N+1][N+1];
        for(int i = 0; i < N; i++){
            dp[0][i] = Matrix[0][i];
        }
        for(int i = 1; i < N; i++){
            for(int j = 0; j < N; j++){
                if(j == 0)
                dp[i][j] = Matrix[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
                else if(j == N - 1)
                dp[i][j] = Matrix[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
                else
                dp[i][j] = Matrix[i][j] + max(dp[i-1][j+1], max(dp[i-1][j-1], dp[i-1][j]));
                
            }
        }
        int max_sum = 0;
        for(int i = 0; i < N; i++){
            max_sum = max(max_sum, dp[N-1][i]);
        }
        return max_sum;
    }
};