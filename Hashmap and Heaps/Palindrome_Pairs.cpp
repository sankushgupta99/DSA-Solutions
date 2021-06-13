class Solution {
public:
    bool isPalindrome(string word){
        int n = word.length();
        for(int i = 0; i < n / 2; i++){
            if(word[i] != word[n-1-i])
                return false;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordsSet;
        
        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            reverse(word.begin(), word.end());
            wordsSet[word] = i;
        }
        
        vector<vector<int>> res;
        for(int i = 0; i < words.size(); i++){ 
            string word = words[i];
            int n = word.length();
            
            for(int k = 0; k <= n; k++){
                if(isPalindrome(word.substr(0, k)) && wordsSet.find(word.substr(k, n-k)) != wordsSet.end()){
                    int j = wordsSet[word.substr(k, n-k)];
                    if(i != j)
                        res.push_back({j, i});
                }
                if(isPalindrome(word.substr(n-k, k)) && wordsSet.find(word.substr(0, n-k)) != wordsSet.end()){
                    int j = wordsSet[word.substr(0, n-k)];
                    if(i != j && k != 0)
                        res.push_back({i, j});
                }
            }
            
        }
        return res;
    }
};