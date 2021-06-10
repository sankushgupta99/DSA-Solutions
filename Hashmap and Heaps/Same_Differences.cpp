#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int t,i,n,j,arr[200010];
	cin>>t;
	
	for(i = 0; i < t; i++){
		cin>>n;
		map<int, int> freq;
		int ans = 0;
		
		for(int j = 1; j <= n; j++){
			cin>>arr[j];
			ans += freq[arr[j]-j];
			freq[arr[j]-j]++;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}