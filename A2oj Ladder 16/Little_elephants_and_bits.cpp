#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string a;
	int flag = 0;
	cin>>a;
	for(int i = 0; i < a.length(); i++){
		if(a[i] == '0'){
			a = a.substr(0, i) + a.substr(i+1, a.length()-i-1);
			flag++;
			break;
		}
	}
	if(!flag)
	a = a.substr(0, a.length()-1);
	
	cout<<a<<endl;
	return 0;
}