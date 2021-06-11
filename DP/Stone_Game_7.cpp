class Solution {
public:
    int dp[1010][1010];
    int psum[1010];
    
    int Sum(int i, int j){
        if(i == 0)
            return psum[j];
        
        return psum[j] - psum[i-1];
    }
    
    int ScoreDiff(int i, int j, vector<int> &stones){
        if(i == j)
            return 0;
        
        if(j == i+1)
            return max(stones[i], stones[j]);
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int score1 = Sum(i, j-1) + min(ScoreDiff(i, j-2, stones)- Sum(i, j-2), ScoreDiff(i+1, j-1, stones) - Sum(i+1, j-1));
        int score2 = Sum(i+1, j) + min(ScoreDiff(i+2, j, stones)- Sum(i+2, j), ScoreDiff(i+1, j-1, stones) - Sum(i+1, j-1));
        
        return dp[i][j] = max(score1, score2);
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        
        psum[0] = stones[0];
        for(int i = 1; i < n; i++){
            psum[i] = psum[i-1] + stones[i];
        }
        
        memset(dp, -1, sizeof(dp));
        return ScoreDiff(0, n-1, stones);
    }
};