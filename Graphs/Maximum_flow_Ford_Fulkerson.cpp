class Solution
{
public:
    int graph[1001][1001];
    
    vector<int> BFS(int N, int src){
        vector<int> par(N+1), visited(N+1);
        for(int i = 1; i <= N; i++){
            par[i] = -1;
            visited[i] = 0;
        }
        
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int v = 1; v <= N; v++){
                if(!visited[v] && graph[u][v] > 0){
                    q.push(v);
                    par[v] = u;
                    visited[v] = 1;
                }
            }
        }
        return par;
    }
    
    void find_min(vector<int> par, int dest, int &min_val){
        for(int v = dest; par[v] != -1; v = par[v]){
            int u = par[v];
            min_val = min(min_val, graph[u][v]);
        }
    }
    
    void subtract_min(vector<int> par, int dest, int min_val){
        for(int v = dest; par[v] != -1; v = par[v]){
            int u = par[v];
            graph[u][v] -= min_val;
        }
    }
    
    void add_back_edges(vector<int> par, int dest, int min_val){
        for(int v = dest; par[v] != -1; v = par[v]){
            int u = par[v];
            graph[v][u] += min_val;
        }
    }
    
    int solve(int N,int M,vector<vector<int>> Edges)
    {
        memset(graph, 0, sizeof(graph));
        
        for(auto i : Edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            graph[u][v] += w;
            graph[v][u] += w;
        }
        
        int src = 1;
        int dest = N;
        int ans = 0;
        vector<int> par;
        
        do{
            par = BFS(N, 1);
            if(par[dest] != -1){
                int min_val = INT_MAX;
                find_min(par, dest, min_val);
                ans += min_val;
                subtract_min(par, dest, min_val);
                add_back_edges(par, dest, min_val);
            }
            
        }while(par[dest] != -1);
        
        return ans;
    }
};