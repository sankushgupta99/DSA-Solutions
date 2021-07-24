class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int low = 0;
            int high = ans;
            
            while(low < high){
                int mid = low + (high - low) / 2;
                if(dp[mid] < nums[i])
                    low = mid + 1;
                else
                    high = mid;
            }
            
            dp[low] = nums[i];
            if(low == ans) ans++;
        }
        
        return ans;
    }
};