class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int arr[2010], j = 0;
        for(int i = 0; i <= 2000; i++){
            while(j != n && i > nums[j]) 
                j++;
            arr[i] = j;
        }
        
        int count = 0;
        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                count += max(0, (arr[nums[i] + nums[j]] - j - 1));
            }
        }
        
        return count;
    }
};