class Solution{
    public:
    void find_combinations(vector<int> &A, int N, int B, vector<int> temp, set<vector<int>> &res){
        if(B == 0 && temp.size() != 0){
            res.insert(temp);
            return;
        }
        else if(N == 0)
        return;
        
        vector<int> temp1 = temp;
        temp.push_back(A[N-1]);
        find_combinations(A, N-1, B-A[N-1], temp, res);
        find_combinations(A, N-1, B, temp1, res);
    }
    vector<vector<int>> combinationSum(vector<int> &A, int N, int B){
        set<vector<int>> res;
        vector<int> temp;
        sort(A.begin(), A.end(), greater<int>());
        
        find_combinations(A, N, B, temp, res);
        
        vector<vector<int>> ans;
        for(auto i : res){
            ans.push_back(i);
        }
        return ans;
    }
};