class Solution {
public:
    int par[1000], rank[1000];
    
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
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size() + 1;
        for(int i = 0; i < n * n; i++){
            par[i] = i;
            rank[i] = 1;
        }
        
        for(int i = 0; i < n-1; i++){
            unionSet(i, i+1);
            unionSet(n*(n-1)+i, n*(n-1)+i+1);
            unionSet(n*i, n*(i+1));
            unionSet(n*i+n-1, n*(i+1)+n-1);
        }
        
        int regions = 1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].length(); j++){
                if(grid[i][j] == '/'){
                    int u = (i*n)+j+1;
                    int v = ((i+1)*n)+j;
                    if(find(u) == find(v))
                        regions++;
                    else
                        unionSet(u, v);
                }
                else if(grid[i][j] == '\\'){
                    int u = (i*n)+j;
                    int v = ((i+1)*n)+j+1;
                    if(find(u) == find(v))
                        regions++;
                    else
                        unionSet(u, v);
                }
            }
        }
        return regions;
    }
};