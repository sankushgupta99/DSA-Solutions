#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int t,i,n,j,x;
	cin>>t;
	for(i = 0; i < t; i++){
		unordered_map<int, int> freq;
		cin>>n;
		for(int j = 0; j < n; j++){
			cin>>x;
			freq[x]++;
		}
		
		unordered_map<int, int> freq2;
		int max_freq = 0, ans;
		for(auto& j : freq){
			freq2[j.second]++;
			if(freq2[j.second] > max_freq || ((freq2[j.second] == max_freq) && (j.second < ans))){
				max_freq = freq2[j.second];
				ans = j.second;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}