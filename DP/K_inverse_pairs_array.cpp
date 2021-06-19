# define mod 1000000007
class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[n+1][k+1];
        int psum[k+1];
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= k; j++){
                if(j == 0)
                    dp[i][j] = 1;
                else if(i == 0)
                    dp[i][j] = 0;
                else{
                    dp[i][j] = (max(0, j-i+1) == 0) ? psum[j] : psum[j] - psum[max(0, j-i+1)-1];
                    if(dp[i][j] < 0)
                        dp[i][j] += mod;
                }
            }
            psum[0] = 1;
            for(int j = 1; j <= k; j++)
                psum[j] = (psum[j-1] + dp[i][j]) % mod;
        }
        return dp[n][k];
    }
};