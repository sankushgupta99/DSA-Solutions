class Solution{
	public:
	void insert_in_map(map<int,vector<int>> &m, int i, vector<int> v){
	    for(auto j:v)
	    m[i].push_back(j);
	}
	long long getCount(int N)
	{
		map<int,vector<int>> nb;
		insert_in_map(nb, 0, {8});
		insert_in_map(nb, 1, {2,4});
		insert_in_map(nb, 2, {1,3,5});
		insert_in_map(nb, 3, {2,6});
		insert_in_map(nb, 4, {1,5,7});
		insert_in_map(nb, 5, {2,4,6,8});
		insert_in_map(nb, 6, {3,5,9});
		insert_in_map(nb, 7, {4,8});
		insert_in_map(nb, 8, {5,7,9,0});
		insert_in_map(nb, 9, {6,8});
		
		long long dp[26][11];
		for(int i = 1; i <= N; i++){
		    for(int j = 0; j <= 9; j++){
		        if(i == 1)
		        dp[i][j] = 1;
		        else{
		            long long val = 0;
		            for(auto k : nb[j]){
		                val += dp[i-1][k];
		            }
		            val += dp[i-1][j];
		            dp[i][j] = val;
		        }
		    }
		}
		long long ans = 0;
		for(int i = 0; i <= 9; i++){
		    ans += dp[N][i];
		}
		return ans;
	}
};