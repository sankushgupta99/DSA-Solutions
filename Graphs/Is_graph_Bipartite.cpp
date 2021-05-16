class Solution {
public:
    void BFS(vector<vector<int>>& adj, int src, int visited[], int &flag){
        visited[src] = 1;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                int curr = q.front();
                q.pop();
                for(auto i : adj[curr]){
                    if(visited[i] && visited[i] == visited[curr])
                        flag++;
                    else if(!visited[i]){
                        q.push(i);
                        if(visited[curr] == 1)
                            visited[i] = 2;
                        else
                            visited[i] = 1;
                    }
                }
                size--;
            }
        }
    }
        
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int visited[n];
        memset(visited, 0, sizeof(visited));
        int flag = 0;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                BFS(graph, i, visited, flag);
            }
        }
        
        return (!flag);
    }
};