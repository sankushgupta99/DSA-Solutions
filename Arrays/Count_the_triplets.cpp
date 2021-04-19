class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    sort(arr, arr + n);
	    int count = 0;
	    for(int i = n - 1; i >= 0 ; i--){
	        int l = 0;
	        int r = i - 1;
	        while(l < r){
	            if(arr[i] < arr[l] + arr[r]){
	                r--;
	            }
	            else if(arr[i] > arr[l] + arr[r]){
	                l++;
	            }
	            else{
	                count++;
	                l++;
	                r--;
	            }
	        }
	    }
	    return count;
	}
};