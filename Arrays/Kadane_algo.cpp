int Solution::maxSubArray(const vector<int> &A) {
    int max_so_far = INT_MIN;
    int max_till_here = 0;
    for(int i = 0; i < A.size(); i++){
        max_till_here += A[i];
        
        if(max_till_here > max_so_far)
        max_so_far = max_till_here;
        
        if(max_till_here < 0)
        max_till_here = 0;
    }
    return max_so_far;
}
