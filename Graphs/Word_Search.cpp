class Solution{
public:
    int visited[110][110];
    void DFS(vector<vector<char>>& board, string word, int i, int j, int index, bool &flag){
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] != word[index] || visited[i][j])
            return;
        
        if(index == word.length() - 1){
            flag = true;
            return;
        }
        
        visited[i][j] = 1;
        DFS(board, word, i+1, j, index+1, flag); DFS(board, word, i-1, j, index+1, flag);
        DFS(board, word, i, j+1, index+1, flag); DFS(board, word, i, j-1, index+1, flag);
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        bool flag = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    memset(visited, 0, sizeof(visited));
                    DFS(board, word, i, j, 0, flag);
                }
            }
        }
        return flag;
    }
};