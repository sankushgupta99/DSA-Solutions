class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curr_reach = 0, max_reach = 0;
        
        for(int i = 0; i < n; i++){
            max_reach = max(max_reach, i + nums[i]);
            
            if(i == curr_reach && i < n-1){
                jumps++;
                curr_reach = max_reach;
            }
        }
        return jumps;
    }
};

//OR

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curr_reach = 0, max_reach = 0;
        
        for(int i = 0; i < n-1; i++){
            max_reach = max(max_reach, i + nums[i]);
            if(max_reach >= n-1)
                return jumps + 1;
            
            if(i == curr_reach){
                jumps++;
                curr_reach = max_reach;
            }
        }
        return jumps;
    }
};