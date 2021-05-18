#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main() {
	int n,k,w,u,v;
	cin>>n;
	vector<pii> adj[n+1];
	for(int i = 1; i <= n; i++){
		cin>>w;
		adj[0].push_back({w, i});
		adj[i].push_back({w, 0});
	}
	cin>>k;
	for(int i = 0; i < k; i++){
		cin>>u>>v>>w;
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}
	
	int visited[n+1], ans = 0;
	memset(visited, 0, sizeof(visited));
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 0});
	
	while(!pq.empty()){
		pii curr = pq.top();
		int v = curr.second;
		int weight = curr.first;
		pq.pop();
		
		if(visited[v])
		continue;
		
		ans += weight;
		visited[v] = 1;
		
		for(auto i : adj[v]){
			int node = i.second;
			if(!visited[node]){
				pq.push(i);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}