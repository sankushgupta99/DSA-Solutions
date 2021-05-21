class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        
        string source;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                source += (board[i][j] + '0');
            }
        }
        
        string dest = "123450";
        queue<string> q;
        q.push(source);
        unordered_set<string> visited;
        visited.insert(source);
        int level = 0;
        
        vector<vector<int>> adj = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                string curr = q.front();
                q.pop();
                
                if(curr == dest)
                    return level;
                
                int pos = 0;
                while(curr[pos] != '0')
                    pos++;
                
                for(int j : adj[pos]){
                    string new_board = curr;
                    swap(new_board[pos], new_board[j]);
                    if(visited.find(new_board) == visited.end()){
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                } 
                size--;
            }
            level++;
        }
        return -1;
    }
};