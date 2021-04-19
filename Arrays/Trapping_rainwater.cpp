class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        int left_max = 0;
        int right_max = 0;
        int lo = 0;
        int hi = n - 1;
        int ans = 0;
        while(lo <= hi){
            if(arr[lo] < arr[hi]){
                if(arr[lo] > left_max)
                left_max = arr[lo];
                ans += (left_max - arr[lo]);
                lo++;
            }
            else{
                if(arr[hi] > right_max)
                right_max = arr[hi];
                ans += (right_max - arr[hi]);
                hi--;
            }
        }
        return ans;
    }
};