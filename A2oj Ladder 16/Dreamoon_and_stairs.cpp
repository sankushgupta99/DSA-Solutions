#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, m, min_moves, max_moves, ans=-1;
	cin>>n>>m;
	min_moves = (n/2);
	if(n % 2 == 1)
	min_moves++;
	max_moves = n;
	
	for(int i = min_moves; i <= max_moves; i++){
		if(i % m == 0){
			ans = i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}