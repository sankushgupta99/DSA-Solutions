#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	int i = 1;
	int j = n * n;
	for(int k = 1; k <= n; k++){
		for(int l = 1; l <= (n / 2); l++){
			cout << i << " ";
			i++;
		}
		for(int l = 1; l <= (n / 2); l++){
			cout << j << " ";
			j--;
		}
		cout<<endl;
	}
	return 0;
}