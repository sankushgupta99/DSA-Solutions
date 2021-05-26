class Solution {
public:
    int par[1002], rank[1002];
    
    int find(int x){
        if(par[x] == x)
            return x;
        int temp = find(par[x]);
        par[x] = temp;
        return temp;
    }
    
    bool unionSet(int x, int y){
        int lox = find(x);
        int loy = find(y);
        
        if(lox == loy)
            return true;
        
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
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        for(int i = 1; i <= n; i++){
            par[i] = i;
            rank[i] = 1;
        }
        
        for(auto i : edges){
            int x = i[0];
            int y = i[1];
            bool flag = unionSet(x, y);
            if(flag) return i;
        }    
        return edges[n-1];
    }
};