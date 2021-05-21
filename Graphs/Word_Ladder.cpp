class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        wordList.push_back(beginWord);
        unordered_set<string> wordSet;
        
        for(auto i : wordList){
            wordSet.insert(i);
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        wordSet.erase(beginWord);
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                pair<string, int> curr = q.front();
                string word = curr.first;
                int dist = curr.second;
                q.pop();
                
                if(word == endWord)
                    return dist;
                
                for(int i = 0; i < word.length(); i++){
                    for(int j = 0; j < 26; j++){
                        string new_word = word;
                        new_word[i] = j + 'a';
                        
                        if(wordSet.find(new_word) != wordSet.end()){
                            q.push({new_word, dist + 1});
                            wordSet.erase(new_word);
                        }
                    }
                }
                size--;
            }
        }
        return 0;
    }
};

//OR

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        wordList.push_back(startWord);
        unordered_set<string> wordset;
        
        for(auto i : wordList)
        wordset.insert(i);
        
        queue<string> q;
        q.push(startWord);
        wordset.erase(startWord);
        int level = 1;
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                string curr = q.front();
                q.pop();
                
                if(curr == targetWord)
                return level;
                
                for(int i = 0; i < curr.length(); i++){
                    for(int j = 0; j < 26; j++){
                        string new_word = curr;
                        new_word[i] = j + 'a';
                        
                        if(wordset.find(new_word) != wordset.end()){
                            q.push(new_word);
                            wordset.erase(new_word);
                        }
                    }
                }
                size--;
            }
            level++;
        }
        return 0;
    }
};