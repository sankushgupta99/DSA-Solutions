int maxCoins(int A[], int N) 
{
    int dp[1001][1001];
    for(int g = 0; g < N; g++){
        for(int i = 0, j = g; j < N; i++, j++){
            if(i == j){
                dp[i][j] = A[i];
            }
            else if(j - i == 1){
                dp[i][j] = max(A[i], A[j]);
            }
            else{
                int val1 = A[i] + min(dp[i+2][j], dp[i+1][j-1]);
                int val2 = A[j] + min(dp[i+1][j-1], dp[i][j-2]);
                dp[i][j] = max(val1, val2);
            }
        }
    }
    return dp[0][N-1];
}

//OR

int dp[1001][1001];
int maxAmount(int arr[], int i, int j){
    if(j == i){
        return arr[i];
    }
    
    if(j - i == 1){
        return max(arr[i], arr[j]);
    }
    
    if(dp[i][j] != -1)
    return dp[i][j];
    
    int val1 = arr[i] + min(maxAmount(arr, i+2, j), maxAmount(arr, i+1, j-1));
    int val2 = arr[j] + min(maxAmount(arr, i+1, j-1), maxAmount(arr, i, j-2));
    return dp[i][j] = max(val1, val2);
}
int maxCoins(int A[], int N) 
{
    memset(dp, -1, sizeof(dp));
    return maxAmount(A, 0, N-1);
}