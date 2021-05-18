#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int dp[4010][5];
	int n, a, b, c;
	cin>>n>>a>>b>>c;
	int wt[5];
	wt[0] = a;
	wt[1] = b;
	wt[2] = c;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 3; j++){
			if(i == 0)
			dp[i][j] = 0;
			else if(j == 0)
			dp[i][j] = INT_MIN;
			else if(j == 1){
				if(i % wt[j-1] == 0){
					dp[i][j] = (i / wt[j-1]);
				}
				else{
					dp[i][j] = INT_MIN;
				}
			}
			else{
				if(wt[j - 1] <= i){
					dp[i][j] = max(1 + dp[i - wt[j-1]][j], dp[i][j-1]);
				}
				else{
					dp[i][j] = dp[i][j-1];
				}
			}
		}
	}
	cout<<dp[n][3]<<endl;
	return 0;
}