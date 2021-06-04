class Solution {
public: 
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendset;
        for(auto i : deadends)
            deadendset.insert(i);
        
        string src = "0000";
        
        queue<string> q;
        unordered_set<string> visited;
        if(deadendset.find(src) == deadendset.end()){
            q.push(src);
            visited.insert(src);
        }
        
        int turns = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                string curr = q.front();
                q.pop();
                
                if(curr == target)
                    return turns;
                
                for(int i = 0; i < 4; i++){
                    string next1 = curr;
                    string next2 = curr;
                    
                    if(curr[i] != '0')
                        next1[i]--;
                    else
                        next1[i] = '9';
                    
                    if(curr[i] != '9')
                        next2[i]++;
                    else
                        next2[i] = '0';
                    
                    if(visited.find(next1) == visited.end() && deadendset.find(next1) == deadendset.end()){
                        q.push(next1);
                        visited.insert(next1);
                    }
                    if(visited.find(next2) == visited.end() && deadendset.find(next2) == deadendset.end()){
                        q.push(next2);
                        visited.insert(next2);
                    }
                }
                size--;
            }
            turns++;
        }
        return -1;
    }
};