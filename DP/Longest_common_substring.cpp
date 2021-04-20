class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int x, int y)
    {
        int dp[x+1][y+1];
        int result=0;
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 || j==0)
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                result = max(result,dp[i][j]);
                }
                else
                dp[i][j]=0;
            }
        }
        return result;
    }
};