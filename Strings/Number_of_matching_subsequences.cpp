class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length();
        int count = 0;
        unordered_map<string, bool> isSubsequence;
            
        for(auto& word : words){
            if(isSubsequence.find(word) == isSubsequence.end()){
                int i = 0, j = 0;
                while(i < n && j < word.length()){
                    if(s[i] == word[j])
                        j++;
                    i++;
                }
                isSubsequence[word] = (j == word.length());
            }
            if(isSubsequence[word])
                count++;
        }
        
        return count;
    }
};