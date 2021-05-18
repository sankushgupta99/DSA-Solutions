#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string s;
	cin>>s;
	int n = s.length();
	int lower = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= 'a' && s[i] <= 'z')
		lower++;
	}
	if(lower >= ((n+1)/2)){
		for(int i = 0; i < s.length(); i++){
			if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] -= ('A' - 'a');
		}
	}
	else{
		for(int i = 0; i < s.length(); i++){
			if(s[i] >= 'a' && s[i] <= 'z')
			s[i] -= ('a' - 'A');
		}
	}
	cout<<s<<endl;
	return 0;
}