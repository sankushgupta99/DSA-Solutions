class Solution{
	public:
	long long subCount(long long arr[], int N, long long K)
	{
	    unordered_map<int, int> occurence;
	    long long psum = 0, count = 0;
	    occurence[0]++;
	    
	    for(int i = 0; i < N; i++){
	        psum = (psum + arr[i]) % K;
	        if(psum < 0)
	        psum += K;
	        
	        count += occurence[psum];
	        occurence[psum]++;
	    }
	    
	    return count;
	}
};