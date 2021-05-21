class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        int trusts[n+1];
        int trusted[n+1];
        memset(trusts, 0, sizeof(trusts));
        memset(trusted, 0, sizeof(trusted));
        
        for(int i = 0; i < trust.size(); i++){
            int a = trust[i][0];
            int b = trust[i][1];
            trusts[a]++;
            trusted[b]++;
        }
        
        for(int i = 1; i <= n; i++){
            if(trusts[i] == 0 && trusted[i] == n-1)
                return i;
        }
        
        return -1;
    }
};