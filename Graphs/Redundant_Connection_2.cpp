class Solution {
public:
    int par[1001]; int rank[1001];
    
    int find(int x){
        if(par[x] == x)
            return x;
        
        int temp = find(par[x]);
        par[x] = temp;
        return temp;
    }
    
    void unionSet(int x, int y){
        int lox = find(x);
        int loy = find(y);
        
        if(lox != loy){
            if(rank[lox] > rank[loy]){
                par[loy] = lox;
            }
            else if(rank[loy] > rank[lox]){
                par[lox] = loy;
            }
            else{
                par[lox] = loy;
                rank[loy]++;
            }
        }
    }
    
    bool DSU(int n, vector<vector<int>>& edges, int blacklist, int &edge_ind){
        for(int i = 1; i <= n; i++){
            par[i] = i;
            rank[i] = 1;
        }
        
        for(int i = 0; i < edges.size(); i++){
            if(i != blacklist){
                int u = edges[i][0];
                int v = edges[i][1];
                if(find(u) == find(v)){
                    edge_ind = i;
                    return true;
                }
                unionSet(u, v);
            }
        }
        
        return false;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int indegree[n+1];
        memset(indegree, -1, sizeof(indegree));
        
        int blacklist = -1; int node;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(indegree[v] == -1){
                indegree[v] = i;
            }
            else{
                node = v;
                blacklist = i;
            }
        }
        
        int edge_ind;
        if(blacklist != -1){
            if(DSU(n, edges, blacklist, edge_ind))
                return edges[indegree[node]];
            else
                return edges[blacklist];
        }
        else{
            DSU(n, edges, blacklist, edge_ind);
            return edges[edge_ind];
        }
    }
};