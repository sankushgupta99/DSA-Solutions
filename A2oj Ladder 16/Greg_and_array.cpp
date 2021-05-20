#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, m, k, arr[100010], op_count[100010], ans[100010], operations[100010][5];
	memset(op_count, 0, sizeof(op_count));
	memset(ans, 0, sizeof(ans));
	cin>>n>>m>>k;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	for(int i = 1; i <= m; i++){
		cin>>operations[i][0]>>operations[i][1]>>operations[i][2];
	}
	for(int i = 1; i <= k; i++){
		int x, y;
		cin>>x>>y;
		op_count[x]++;
		op_count[y+1]--;
	}
	for(int i = 1; i <= m; i++){
		op_count[i] += op_count[i-1];
	}
	for(int i = 1; i <= m; i++){
		int li = operations[i][0];
		int ri = operations[i][1];
		int di = operations[i][2];
		ans[li] += (di * op_count[i]);
		ans[ri+1] -= (di * op_count[i]);
	}
	for(int i = 1; i <= n; i++){
		ans[i] += ans[i-1];
	}
	for(int i = 1; i <= n; i++){
		ans[i] += arr[i];
	}
	for(int i = 1; i <= n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}