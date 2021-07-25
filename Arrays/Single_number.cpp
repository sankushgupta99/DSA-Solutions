class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int num = 0;
        
        for(int i = 0; i < nums.size(); i++)
            num = num ^ nums[i];
        
        return num;
    }
};