class Solution{
	public:
	int minDiffernce(int arr[], int n) 
	{ 
	    int sum = 0;
	    for(int i = 0; i < n; i++){
	        sum += arr[i];
	    }
	    int dp[n+1][sum+1];
	    for(int i = 0; i <= n; i++){
	        for(int j = 0; j <= sum; j++){
	            if(i == 0)
	            dp[i][j] = 0;
	            if(j == 0)
	            dp[i][j] = 1;
	        }
	    }
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j <= sum; j++){
	            if(arr[i-1] <= j){
	                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    int mid = sum / 2;
	    for(int j = mid; j >=0; j--){
	        if(dp[n][j] == 1)
	        return sum - (2 * j);
	    }
	} 
};