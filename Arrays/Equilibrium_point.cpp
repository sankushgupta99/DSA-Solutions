class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if(n == 1)
            return 1;
            
        int l = -1, r = n, leftSum = 0, rightSum = 0;
        while(l < r - 2){
            if(leftSum < rightSum){
                leftSum += a[++l];
            }
            else{
                rightSum += a[--r];
            }
        }
        
        if(leftSum == rightSum)
            return r;
            
        return -1;
    }

};