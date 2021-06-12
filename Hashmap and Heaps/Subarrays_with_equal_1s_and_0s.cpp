class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        map<int, int> occurence;
        int pc0 = 0, pc1= 0;
        occurence[0]++;
        long long subarray_count = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] == 0)
                pc0++;
            else
                pc1++;
            
            subarray_count += occurence[pc0 - pc1];
            occurence[pc0 - pc1]++;
        }
        
        return subarray_count;
    }
};