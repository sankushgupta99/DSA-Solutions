class Solution{
public:
    int dp[201][201][2];
    int Bool_Par(string S, int i, int j, bool isTrue){
        if(i == j){
            if(isTrue == true)
            return (S[i] == 'T');
            else
            return (S[i] == 'F');
        }
        if(isTrue == true && dp[i][j][1] != -1)
        return dp[i][j][1];
        if(isTrue == false && dp[i][j][0] != -1)
        return dp[i][j][0];
        int ans = 0;
        int lt, lf, rt, rf;
        for(int k = i + 1; k <= j-1; k += 2){
            if(dp[i][k-1][1] != -1)
                lt = dp[i][k-1][1];
            else
                lt = Bool_Par(S, i, k-1, true);
            if(dp[i][k-1][0] != -1)
                lf = dp[i][k-1][0];
            else
                lf = Bool_Par(S, i, k-1, false);
            if(dp[k+1][j][1] != -1)
                rt = dp[k+1][j][1];
            else
                rt = Bool_Par(S, k+1, j, true);
            if(dp[k+1][j][0] != -1)
                rf = dp[k+1][j][0];
            else
                rf = Bool_Par(S, k+1, j , false);
            if(isTrue == true){
                if(S[k] == '&'){
                    ans = (ans + (rt*lt)) % 1003;
                }
                else if(S[k] =='|'){
                    ans = (ans + (lt*rt + lt*rf + lf*rt)) % 1003;
                }
                else{
                    ans = (ans + (lt*rf + lf*rt)) % 1003;
                }
            } 
            else{
                if(S[k] == '&'){
                    ans = (ans + (lf*rf + lf*rt + lt*rf)) % 1003;
                }
                else if(S[k] =='|'){
                    ans = (ans + (lf*rf)) % 1003;
                }
                else{
                    ans = (ans + (lt*rt + lf*rf)) % 1003;
                }
            }
        }
        if(isTrue == true)
        return dp[i][j][1] = ans;
        else
        return dp[i][j][0] = ans;
    }
    int countWays(int N, string S){
        memset(dp, -1, sizeof(dp));
        return Bool_Par(S, 0, N - 1, true);
    }
};