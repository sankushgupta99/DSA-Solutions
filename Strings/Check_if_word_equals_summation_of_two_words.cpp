class Solution {
public:
    int findVal(string &word){
        int val = 0;
        
        for(int i = 0; i < word.length(); i++){
            val = (val * 10) + (word[i] - 'a');
        }
        
        return val;
    } 
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        
        return (findVal(firstWord) + findVal(secondWord) == findVal(targetWord));
        
    }
};