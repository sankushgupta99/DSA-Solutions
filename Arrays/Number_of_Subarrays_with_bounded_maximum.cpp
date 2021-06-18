class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int si = 0, ei = 0, prevc = 0, ans = 0;
        int n = nums.size();
        
        while(ei < n){
            if(nums[ei] >= left && nums[ei] <= right){
                prevc = ei - si + 1;
                ans += prevc;
            }
            else if(nums[ei] < left){
                ans += prevc;
            }
            else{
                si = ei + 1;
                prevc = 0;
            }
            ei++;
        }
        
        return ans;
    }
};

//OR

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int count = 0, count2 = 0, excluded_sum = 0, res = 0;
        
        for(int& num : nums){
            if(num < left){
                count++;
                count2++;
            }
            else if(num > right){
                excluded_sum += ((count * (count + 1)) / 2);
                res += ((count2 * (count2 + 1)) / 2);
                res -= excluded_sum;
                count = 0; count2 = 0; excluded_sum = 0;
            }
            else{
                excluded_sum += ((count * (count + 1)) / 2);
                count2++; count = 0;
            }
        }
        excluded_sum += ((count * (count + 1)) / 2);
        res += ((count2 * (count2 + 1)) / 2);
        res -= excluded_sum;
        return res;
    }
};