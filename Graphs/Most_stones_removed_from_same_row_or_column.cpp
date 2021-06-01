class Solution {
public:
    int par[20002], rank[20002];
    
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
    
    int removeStones(vector<vector<int>>& stones) {
        for(int i = 0; i < 20002; i++){
            par[i] = -1;
            rank[i] = 1;
        }
        
        int stone_sets_left = 0;
        
        for(auto i : stones){
            int x = i[0];
            int y = 10001 + i[1];
            
            if(par[x] == -1){
                par[x] = x;
                stone_sets_left++;
            }
            if(par[y] == -1){
                par[y] = y;
                stone_sets_left++;
            }
            
            if(find(x) != find(y)){
                unionSet(x, y);
                stone_sets_left--;
            }
        }
        return stones.size() - stone_sets_left;
    }
};