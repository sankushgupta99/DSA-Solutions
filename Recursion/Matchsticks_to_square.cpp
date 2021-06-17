class Solution {
public:
    bool solve(int ind, vector<int>& matchsticks, int target, vector<int>& sum){
        if(ind == matchsticks.size()){
            return (sum[0] == sum[1] && sum[1] == sum[2] && sum[2] == target);
        }
        
        for(int i = 0; i < 4; i++){
            if(sum[i] + matchsticks[ind] > target) continue;
            sum[i] += matchsticks[ind];
            if(solve(ind + 1, matchsticks, target, sum))
                return true;
            sum[i] -= matchsticks[ind];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() == 0)
            return false;
        
        int length_sum = 0;
        for(int len : matchsticks){
            length_sum += len;
        }
        
        if(length_sum % 4)
            return false;
        
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sum(4, 0);
        sum[0] += matchsticks[0];
        
        return solve(1, matchsticks, length_sum / 4, sum);
    }
};