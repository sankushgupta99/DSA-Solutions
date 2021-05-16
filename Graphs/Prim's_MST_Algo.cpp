#include <bits/stdc++.h>
#define pi pair<int, int>
#define int long long
using namespace std;

signed main() {
	int n, m;
	cin>>n>>m;
	vector<pi> adj[n+1];
	
	for(int i = 0; i < m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}
	
	int ans = 0;
	int visited[n+1];
	memset(visited, 0, sizeof(visited));
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	
	pq.push({0, 1});
	
	while(!pq.empty()){
		pi curr = pq.top();
		pq.pop();
		
		if(visited[curr.second])
		continue;
		
		visited[curr.second] = 1;
		ans += curr.first;
		for(auto i : adj[curr.second]){
			pq.push(i);
		}
	}
	
	cout<<ans<<endl;
	return 0;
}