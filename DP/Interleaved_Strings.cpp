class Solution{
  public:
    bool isInterleave(string A, string B, string C) 
    {
        int len1 = A.length();
        int len2 = B.length();
        
        if(len1 + len2 != C.length())
        return false;
        
        bool dp[len1+1][len2+1];
        
        memset(dp, false, sizeof(dp));
        
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0 && B[j-1] == C[j-1]){
                    dp[i][j] = dp[i][j-1];
                }
                else if(j == 0 && A[i-1] == C[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else if(A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else if(A[i-1] != C[i+j-1] && B[j-1] == C[i+j-1]){
                    dp[i][j] = dp[i][j-1];
                }
                else if(A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1]){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[len1][len2];
    }

};