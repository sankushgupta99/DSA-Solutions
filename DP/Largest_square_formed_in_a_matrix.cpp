class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int dp[n][m];
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = mat[i][j];
                    res = max(res, dp[i][j]);
                }
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                }
                else{
                    int sub_ans = min(dp[i-1][j], dp[i][j-1]);
                    if(mat[i-sub_ans][j-sub_ans] == 1)
                    dp[i][j] = sub_ans + 1;
                    else
                    dp[i][j] = sub_ans;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};