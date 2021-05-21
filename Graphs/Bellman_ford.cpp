class Solution {
public:
	int BellmanFord(int n, vector<vector<int>>edges){
	    int dist[n];
	    for(int i = 1; i < n; i++)
	        dist[i] = INT_MAX;
	    dist[0] = 0;

	    for(int i = 1; i <= n-1; i++){
	        for(auto j : edges){
	            int u = j[0];
	            int v = j[1];
	            int w = j[2];
	            
	            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
	            dist[v] = dist[u] + w;
	        }
	    }
	    int flag = 0;
	    for(auto j : edges){
            int u = j[0];
            int v = j[1];
            int w = j[2];

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                flag++;
                break;
            }
	    }
	    if(flag)
        cout<<-1<<endl;
        else{
            for(int i = 0; i < n; i++)
            cout<<dist[i]<<" ";
            cout<<endl;
        }
	}
};