class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int overall_max = INT_MIN;
        int curr_sum = 0;
        
        for(int i = 0; i < n; i++){
            curr_sum += nums[i];
            overall_max = max(overall_max, curr_sum);
            if(curr_sum < 0)
                curr_sum = 0;
        }
        
        return overall_max;
    }
};