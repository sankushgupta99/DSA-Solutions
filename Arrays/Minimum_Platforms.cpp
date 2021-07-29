lass Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
    	sort(dep, dep + n);
    	int max_overlap = 0, curr_overlap = 0, i = 0, j = 0;
    	
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){
    	        curr_overlap++;
    	        i++;
    	    }
    	    else{
    	        curr_overlap--;
    	        j++;
    	    }
    	    max_overlap = max(max_overlap, curr_overlap);
    	}
    	
    	return max_overlap;
    }
};