class Solution{
public:
    int palindromicPartition(string str)
    {
        int isPal[510][510];
        int len  = str.length();
        for(int g = 0; g < len; g++){
            for(int i = 0, j = g; j < len; i++,j++){
                if(i == j){
                    isPal[i][j] = 1;
                }
                else if(j == i + 1){
                    if(str[i] == str[j])
                    isPal[i][j] = 1;
                    else
                    isPal[i][j] = 0;
                }
                else{
                    if(str[i] == str[j] && isPal[i+1][j-1] == 1)
                    isPal[i][j] = 1;
                    else
                    isPal[i][j] = 0;
                }
            }
        }
        int dp[510];
        dp[0] = 0;
        for(int i = 1; i < len; i++){
            if(isPal[0][i])
                dp[i] = 0;
            else{
                int min = i;
                for(int j = i - 1; j >= 0; j--){
                    if(isPal[j+1][i] && dp[j] + 1 < min){
                        min = dp[j] + 1;
                    }
                }
                dp[i] = min;
            }
        }
        return dp[len-1];
    }
};