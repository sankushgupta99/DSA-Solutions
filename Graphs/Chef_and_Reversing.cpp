#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
	int n, m, x, y;
	cin>>n>>m;
	vector<pii> adj[n+1];
	
	for(int i = 0; i < m; i++){
		cin>>x>>y;
		if(x == y)
		continue;
		adj[x].push_back({0, y});
		adj[y].push_back({1, x});
	}
	
	int ans[n+1];
	memset(ans, -1, sizeof(ans));
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 1});
	
	while(!pq.empty()){
		pii curr = pq.top();
		int v = curr.second;
		int w = curr.first;
		pq.pop();
		
		if(ans[v] != -1)
		continue;
		
		ans[v] = w;
		for(auto i : adj[v]){
			int weight = i.first;
			int node = i.second;
			if(ans[node] == -1){
				pq.push({w + weight, node});
			}
		}
	}
	cout<<ans[n]<<endl;
	return 0;
}

//OR
//0-1 BFS

#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
	int n,m,x,y;
	cin>>n>>m;
	vector<pii> adj[n+1];
	
	for(int i = 0; i < m; i++){
		cin>>x>>y;
		adj[x].push_back({0, y});
		adj[y].push_back({1, x});
	}
	
	int ans[n+1];
	memset(ans, -1, sizeof(ans));
	queue<pii> q1, q2;
	q1.push({0, 1});
	
	while(!q1.empty() || !q2.empty()){
		if(q1.empty()){
			swap(q1, q2);
		}
		pii curr = q1.front();
		int w = curr.first;
		int v = curr.second;
		q1.pop();
		
		if(ans[v] != -1)
		continue;
		
		ans[v] = w;
		for(auto i : adj[v]){
			int weight = i.first;
			int node = i.second;
			if(ans[node] == -1){
				if(weight == 0){
					q1.push({w + weight, node});
				}
				else{
					q2.push({w + weight, node});
				}
			}
		}
	}
	cout<<ans[n]<<endl;
	return 0;
}