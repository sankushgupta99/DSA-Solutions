class Solution{
	public:
	int maxCalories(int arr[], int n)
	{
		int dp[n][3];
        dp[0][0] = 0; 
        dp[0][1] = arr[0];
        dp[0][2] = 0;
        
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][1] + arr[i];
            dp[i][1] = dp[i-1][2] + arr[i];
            dp[i][2] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        }
        
        return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
	}
};