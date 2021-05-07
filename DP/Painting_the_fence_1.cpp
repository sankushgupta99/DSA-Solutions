#define mod 1000000007
class Solution{
    public:
    long long countWays(int n, int k){
        long long dp[n+1][3];
        dp[1][0] = 0;
        dp[1][1] = k;
        for(int i = 2; i <= n; i++){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (((dp[i-1][0] + dp[i-1][1]) % mod) * (k-1)) % mod;
        }
        return (dp[n][0] + dp[n][1]) % mod;
    }
};