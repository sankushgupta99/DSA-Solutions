class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0, max_reachable_ind = 0;
        
        while(i <= max_reachable_ind && i < n){
            max_reachable_ind = max(max_reachable_ind, i + nums[i]);
            i++;
        }
        
        return (i == n);
    }
};