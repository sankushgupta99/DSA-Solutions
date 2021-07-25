class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int ind = 1;
        
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[ind-1])
                nums[ind++] = nums[i];
        }
        
        return ind;
    }
};