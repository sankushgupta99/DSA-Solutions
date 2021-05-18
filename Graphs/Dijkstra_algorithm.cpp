#define pii pair<int, int>
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans;
        for(int i = 0; i < V; i++)
        ans.push_back(-1);
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, S});
        
        while(!pq.empty()){
            pii curr = pq.top();
            int v = curr.second;
            int w = curr.first;
            pq.pop();
            
            if(ans[v] != -1)
            continue;
            
            ans[v] = w;
            for(auto i : adj[v]){
                int node = i[0];
                int weight = i[1];
                if(ans[node] == -1){
                    pq.push({w + weight, node});
                }
            }
        }
        return ans;
    }
};