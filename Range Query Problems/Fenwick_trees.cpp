#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[1000010], prefix_sum[1000010], farr[1000010];

void preprocess(int n){
	prefix_sum[0] = 0;
	for(int i = 1; i <= n; i++){
		prefix_sum[i] = prefix_sum[i-1] + arr[i];
	}
	
	for(int i = 1; i <= n; i++){
		farr[i] = prefix_sum[i] - prefix_sum[i - (i & -i)];
	}
}

void process_query(int l, int r){
	int ans = 0;
	
	while(r > 0){
		ans += farr[r];
		r = r - (r & -r);
	}
	
	l--;
	while(l > 0){
		ans -= farr[l];
		l = l - (l & -l);
	}
	
	cout<<ans<<endl;
}

void update(int n, int i, int x){
	while(i <= n){
		farr[i] += x;
		i = i + (i & -i);
	}
}

signed main() {
	int n, i, j, q;
	char s;
	
	cin>>n;
	for(i = 1; i <= n; i++){
		cin>>arr[i];
	}
	
	preprocess(n);
	
	cin>>q;
	for(j = 0; j < q; j++){
		cin>>s;
		if(s == 'q'){
			int l, r;
			cin>>l>>r;
			process_query(l, r);
		}
		else{
			int i, x;
			cin>>i>>x;
			update(n, i, x);
		}
	}
	return 0;
}