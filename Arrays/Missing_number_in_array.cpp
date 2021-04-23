class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        int sum = 0;
        for(int i = 0; i < n - 1; i++){
            sum += array[i];
        }
        long long int required_sum = (n * (n+1)) / 2;
        int missing_no = required_sum - sum;
        return missing_no;
    }
};