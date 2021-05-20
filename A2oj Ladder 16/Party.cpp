#include <bits/stdc++.h>
using namespace std;
int BFS(vector<int> adj[], int src){
	queue<int> q;
	q.push(src);
	int level = 0;
	while(!q.empty()){
		level++;
		int size = q.size();
		while(size > 0){
			int curr = q.front();
			q.pop();
			for(int i : adj[curr]){
				q.push(i);
			}
			size--;
		}
	}
	return level;
}
int main() {
	int n, arr[2010];
	vector<int> adj[2010];
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
		adj[arr[i]].push_back(i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(arr[i] == -1){
			int temp_ans = BFS(adj, i);
			ans = max(ans, temp_ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}