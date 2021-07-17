class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        unordered_set<string> hash;
        
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                int k = j+1;
                int l = n-1;
                
                while(k < l){
                    if(nums[i] + nums[j] + nums[k] + nums[l] == target){
                        string str = to_string(nums[i]) + '#' + to_string(nums[j]) + '#' + 
                            to_string(nums[k]) + '#' + to_string(nums[l]);
                        
                        if(hash.find(str) == hash.end()){
                            res.push_back({nums[i], nums[j], nums[k], nums[l]});
                            hash.insert(str);
                        }
                        k++;
                        l--;
                    }
                    else if(nums[i] + nums[j] + nums[k] + nums[l] < target)
                        k++;
                    else
                        l--;
                }
                
            }
        }
        
        return res;
    }
};

//OR

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                int k = j+1;
                int l = n-1;
                
                while(k < l){
                    if(nums[i] + nums[j] + nums[k] + nums[l] == target){
                        s.insert({nums[i], nums[j], nums[k], nums[l]}); 
                        k++;
                        l--;
                    }
                    else if(nums[i] + nums[j] + nums[k] + nums[l] < target)
                        k++;
                    else
                        l--;
                }
                
            }
        }
        
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};