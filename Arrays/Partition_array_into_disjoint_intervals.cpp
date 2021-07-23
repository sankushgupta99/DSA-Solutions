class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int leftmax[n], rightmin[n];
        leftmax[0] = nums[0];
        rightmin[n-1] = nums[n-1];
        
        for(int i = 1; i < n; i++)
            leftmax[i] = max(leftmax[i-1], nums[i]);
        for(int i = n-2; i >= 0; i--)
            rightmin[i] = min(rightmin[i+1], nums[i]);
        
        int left_ind = 0;
        while(leftmax[left_ind] > rightmin[left_ind + 1] && (left_ind + 1) < (n - 1))
            left_ind++;
        
        return left_ind + 1;
    }
};

//OR

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int leftmax[n], rightmin[n];
        leftmax[0] = nums[0];
        rightmin[n-1] = nums[n-1];
        
        for(int i = 1; i < n; i++)
            leftmax[i] = max(leftmax[i-1], nums[i]);
        for(int i = n-2; i >= 0; i--)
            rightmin[i] = min(rightmin[i+1], nums[i]);
        
        int left_ind = 0;
        while(leftmax[left_ind] > rightmin[left_ind + 1])
            left_ind++;
        
        return left_ind + 1;
    }
};