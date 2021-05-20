#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cout<<setprecision(15);
	string s1, s2;
	double ans = 1;
	cin>>s1>>s2;
	int dest = 0;
	for(int i = 0; i < s1.length(); i++){
		if(s1[i] == '+')
		dest++;
		else
		dest--;
	}
	int unrec = 0;
	int curr = 0;
	for(int i = 0; i < s2.length(); i++){
		if(s2[i] == '+')
		curr++;
		else if(s2[i] == '-')
		curr--;
		else
		unrec++;
	}
	int diff = ((dest - curr + unrec) / 2);
	if(diff > unrec || diff < 0){
		ans = 0;
		cout<<ans<<endl;
	}
	else{
		for(int i = 0; i < unrec; i++){
			ans *= (0.5);
		}
		for(int i = 1; i <= unrec; i++){
			ans *= (i);
		}
		for(int i = 1; i <= diff; i++){
			ans /= (i);
		}
		for(int i = 1; i <= unrec - diff; i++){
			ans /= (i);
		}
		cout<<ans<<endl;
	}
	return 0;
}