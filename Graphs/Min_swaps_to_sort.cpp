class Solution 
{
    public:
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int, int>> sorted;
	    for(int i = 0; i < n; i++){
	        sorted.push_back({nums[i], i});
	    }
	    sort(sorted.begin(), sorted.end());
	    
	    vector<int> vis(n, 0);
	    
	    int min_swaps = 0;
	    for(int i = 0; i < n; i++){
	        if(vis[i] == 1 || nums[i] == sorted[i].first){
	            vis[i] = 1;
	            continue;
	        }
	        int j = i;
	        int cycle_len = 0;
	        while(vis[j] != 1){
	            vis[j] = 1;
	            j = sorted[j].second;
	            cycle_len++;
	        }
	        min_swaps += (cycle_len - 1);
	    }
	    return min_swaps;
	}
};