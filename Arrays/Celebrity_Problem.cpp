class Solution {
    public:
    int celebrity(vector<vector<int> >& M, int n) {
        int i = 0;
        int j = n - 1;
        while(i < j){
            if(M[i][j] == 1)
            i++;
            else{
                j--;
            }
        }
        for(int j = 0; j < n - 1; j++){
            if(M[i][j] == 1 && i != j)
            return -1;
        }
        for(int j = 0; j < n - 1; j++){
            if(M[j][i] == 0 && i != j)
            return -1;
        }
        return i;
    }
};