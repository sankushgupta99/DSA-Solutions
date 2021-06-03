class Solution {
public:
    int par[1001], rank[1001];
    
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
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({w, i, j});
            }
        }
        
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 1;
        }
        
        int ans = 0;
        int edge_count = 0;
        
        while(edge_count < n-1){
            vector<int> curr = pq.top();
            pq.pop();
            
            int w = curr[0];
            int u = curr[1];
            int v = curr[2];
            
            if(find(u) != find(v)){
                ans += w;
                edge_count++;
                unionSet(u, v);
            }
        }
        return ans;
    }
};