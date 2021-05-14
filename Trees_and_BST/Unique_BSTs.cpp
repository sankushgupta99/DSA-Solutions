class Solution {
public:
    
    long long dp[30];
    
    int numTrees(int n) {
        if(n == 0 || n == 1)
            return 1;
        
        if(dp[n] != 0)
            return dp[n];
        
        long long total_unique_BST = 0;
        for(int i = 1; i <= n; i++){
            total_unique_BST += (numTrees(i - 1) * numTrees(n - i));
        }
        
        return dp[n] = total_unique_BST;
    }
};

//OR

#define mod 1000000007
class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    long long dp[10010];
    long long numTrees(long long N) 
    {
        if(N == 0 || N == 1)
        return 1;
        
        if(dp[N] != 0)
        return dp[N];
        
        long long total_unique_BST = 0;
        for(int i = 1; i <= N; i++){
            long long prod = ((numTrees(i - 1) * numTrees(N - i)) % mod);
            total_unique_BST = ((total_unique_BST + prod) % mod);
        }
        
        return dp[N] = (total_unique_BST % mod);
    }
};