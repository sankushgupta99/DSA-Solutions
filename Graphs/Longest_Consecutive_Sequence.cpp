class Solution {
public:
    map<int, int> par;
    map<int, int> size;
    
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
        
        if(size[lox] > size[loy]){
            par[loy] = lox;
            size[lox] += size[loy];
        }
        else{
            par[lox] = loy;
            size[loy] += size[lox];
        }
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){ 
            if(par.find(nums[i]) == par.end()){
                par[nums[i]] = nums[i];
                size[nums[i]] = 1;
            
                if(par.find(nums[i] - 1) != par.end())
                    unionSet(nums[i], nums[i] - 1);

                if(par.find(nums[i] + 1) != par.end())
                    unionSet(nums[i], nums[i] + 1);
            }
        }
        
        int max_consecutive = 0;
        for(auto i : par){
            if(i.first == i.second){
                max_consecutive = max(max_consecutive, size[i.first]);
            }
        }
        
        return max_consecutive;
    }
};