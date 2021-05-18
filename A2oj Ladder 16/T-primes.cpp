#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> primes;
    for(int i = 2; i <= 1000; i++){
    	int flag = 0;
    	for(int j = 2; j <= sqrt(i); j++){
    		if(i % j == 0)
    		flag++;
    	}
    	if(!flag)
    	primes.push_back(i);
    }
	int n,i,x,sqrtx;
	cin>>n;
	for(i = 0; i < n; i++){
		cin>>x;
		sqrtx = sqrt(x);
		if(sqrtx * sqrtx != x){
			cout<<"NO"<<endl;
		}
		else{
			x = sqrt(x);
			int flag = 0;
			for(int j : primes){
				if(j > sqrt(x))
				break;
				
				if(x % j == 0){
					flag++;
					break;
				}
			}
			if(!flag && x != 1)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
	}
	return 0;
}