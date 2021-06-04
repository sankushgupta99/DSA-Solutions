class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        map<int, vector<int>> adj;
        int indegree[K];
        memset(indegree, 0, sizeof(indegree));
        
        for(int i = 1; i < N; i++){
            string word1 = dict[i-1];
            string word2 = dict[i];
            
            for(int j = 0; j < min(word1.length(), word2.length()); j++){
                if(word1[j] != word2[j]){
                    int u = word1[j] - 'a';
                    int v = word2[j] - 'a';
                    adj[u].push_back(v);
                    indegree[v]++;
                    break;
                }
            }
        }
        
        string charOrder;
        queue<int> q;
        for(int i = 0; i < K; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            charOrder += (curr + 'a');
            
            for(auto i : adj[curr]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        return charOrder;
    }
};