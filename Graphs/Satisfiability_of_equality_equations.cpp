class Solution {
public:
    int par[30], rank[30];
    
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
    
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; i++){
            par[i] = i;
            rank[i] = 1;
        }
        
        for(auto str : equations){
            if(str[1] == '='){
                int x = str[0] - 'a';
                int y = str[3] - 'a';
                unionSet(x, y);
            }
        }
        
        for(auto str : equations){
            if(str[1] == '!'){
                int x = str[0] - 'a';
                int y = str[3] - 'a';
                if(find(x) == find(y)) 
                    return false;
            }
        }
        return true;
    }
};