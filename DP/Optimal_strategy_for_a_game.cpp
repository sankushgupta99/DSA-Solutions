long long dp[1001][1001];
long long maxAmount(int arr[], int i, int j){
    if(j - i == 1){
        return max(arr[i], arr[j]);
    }
    
    if(dp[i][j] != -1)
    return dp[i][j];
    
    long long val1 = arr[i] + min(maxAmount(arr, i+2, j), maxAmount(arr, i+1, j-1));
    long long val2 = arr[j] + min(maxAmount(arr, i+1, j-1), maxAmount(arr, i, j-2));
    return dp[i][j] = max(val1, val2);
}
long long maximumAmount(int arr[], int n) 
{
    memset(dp, -1, sizeof(dp));
    return maxAmount(arr, 0, n-1);
}