#include<bits/stdc++.h>
using namespace std;

map<string, string> par;
map<string, int> height;

string find(string x){
	if(par[x] == x)
	return x;
	
	string temp = find(par[x]);
	par[x] = temp;
	return temp;
}

void unionSet(string x, string y){
	string lox = find(x);
	string loy = find(y);
	
	if(lox != loy){
		if(height[lox] > height[loy]){
			par[loy] = lox;
		}
		else if(height[loy] > height[lox]){
			par[lox] = loy;
		}
		else{
			par[lox] = loy;
			height[loy]++;
		}
	}
}

bool areSentencesSimilarTwo(vector<string> words1, vector<string> words2, vector<vector<string>> pairs){
	if(words1.size() != words2.size())
		return false;
		
	for(auto i : pairs){
		string str1 = i[0];
		string str2 = i[1];
		if(par.find(str1) == par.end()){
			par[str1] = str1;
			height[str1] = 1;
		}
		if(par.find(str2) == par.end()){
			par[str2] = str2;
			height[str1] = 1;
		}
		unionSet(str1, str2);
	}
	
	for(int i = 0; i < words1.size(); i++){
		string str1 = words1[i];
		string str2 = words2[i];
		if(find(str1) != find(str2))
		return false;
	}
	return true;
}

int main(){
	vector<string> words1 = {"great", "acting", "skills"};
	vector<string> words2 = {"fine", "drama", "talent"};
	vector<vector<string>> pairs = {{"great", "good"}, {"fine", "good"}, {"acting","drama"}, {"skills","talent"}};
	cout<<areSentencesSimilarTwo(words1, words2, pairs)<<endl;
	return 0;
}