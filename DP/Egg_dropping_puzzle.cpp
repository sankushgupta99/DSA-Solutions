class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int eggDrop_Util(int e, int f){
        if(e == 1)
        return f;
        if(f == 1 || f == 0)
        return f;
        if(dp[e][f] != -1)
        return dp[e][f];
        int min = INT_MAX - 1;
        for(int i = 1; i <= f; i++){
            int temp_ans = 1 + max(eggDrop_Util(e-1, i-1), eggDrop_Util(e, f-i));
            if(temp_ans < min)
            min = temp_ans;
        }
        return dp[e][f] = min; 
        
    }
    int eggDrop(int n, int k) 
    {
        memset(dp, -1, sizeof(dp));
        return eggDrop_Util(n, k);
    }
};