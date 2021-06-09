class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> occurence;
        int psum = 0, count = 0;
        occurence[0]++;
        
        for(int i = 0; i < nums.size(); i++){
            psum += nums[i];
            count += occurence[psum - k];
            occurence[psum]++;
        }
        
        return count;
    }
};