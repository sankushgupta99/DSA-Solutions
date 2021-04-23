class Solution{
public:
int dp[101][101];
    int MCM(int arr[], int i, int j){
        if(i >= j)
        return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            int temp_ans = MCM(arr, i, k) + MCM(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
            ans = min(ans, temp_ans);
        }
        return dp[i][j] = ans;
    } 
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        return MCM(arr, 1, N - 1);
    }
};