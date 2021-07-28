class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest_sum = 1000000;
        
        for(int i = 0; i < n-2; i++){
            int j = i+1, k = n-1;
            while(j < k){
                if(abs(nums[i] + nums[j] + nums[k] - target) < abs(closest_sum - target)){
                    closest_sum = nums[i] + nums[j] + nums[k];
                    if(closest_sum == target) 
                        return closest_sum; 
                }
                if(nums[i] + nums[j] + nums[k] < target)
                    j++;
                else 
                    k--;
            }
        }
        
        return closest_sum;
    }
};