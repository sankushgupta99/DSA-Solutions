class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n+1];
	    dp[0]=0;
	    int res=0;
	    for(int i=1;i<=n;i++){
	        dp[i] = arr[i-1];
	        for(int j = i-1; j >=1; j--){
	            if(arr[j-1]<arr[i-1]){
	                dp[i]=max(dp[i], dp[j]+arr[i-1]);
	            }
	        }
	        res=max(res,dp[i]);
	    }
	    return res;
	}  
};
