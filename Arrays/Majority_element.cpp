class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int result, max_freq = 0;
        unordered_map<int,int> freq;
        
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > max_freq){
                max_freq = freq[nums[i]];
                result = nums[i];
            }
        }
        
        return result;
    }
};