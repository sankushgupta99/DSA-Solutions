class Solution {
public:
    int subtreeSize(int src, int N, vector<int>adj[], int tree_size[], int visited[]){
        visited[src] = 1;
        if(src != 0 && adj[src].size() == 1){
            tree_size[src] = 1;
            return 1;
        }
        for(int i = 0; i < adj[src].size(); i++){
            if(!visited[adj[src][i]]){
                tree_size[src] += subtreeSize(adj[src][i], N, adj, tree_size, visited);
            }
        }
        return tree_size[src];
    }
    int level_order(int src, vector<int>adj[], int visited[]){
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        int level = -1;
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            while(size > 0){
                int rem = q.front();
                q.pop();
                res += level;
                for(int i = 0; i < adj[rem].size();i++){
                    if(!visited[adj[rem][i]]){
                        q.push(adj[rem][i]);
                        visited[adj[rem][i]] = 1;
                    }
                }
                size--;
            }
        }
        return res;
    }
    void level_order1(int N, int src, vector<int>adj[], int visited[], int dist_sum[],int tree_size[]){
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                int rem = q.front();
                q.pop();
                for(int i = 0; i < adj[rem].size();i++){
                    if(!visited[adj[rem][i]]){
                        dist_sum[adj[rem][i]] = dist_sum[rem] + N - (2 * tree_size[adj[rem][i]]);
                        q.push(adj[rem][i]);
                        visited[adj[rem][i]] = 1;
                    }
                }
                size--;
            }
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> adj[N+1];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int tree_size[N+1];
        int dist_sum[N];
        int visited[N+1], visited1[N+1], visited2[N+1];
        for(int i = 0; i < N; i++)
        {
            visited[i] = 0;
            visited1[i] = 0;
            visited2[i] = 0;
            tree_size[i] = 1;
            dist_sum[i] = 0;
        }
        subtreeSize(0, N, adj, tree_size, visited);
        //for(int i = 0; i < N; i++)
        //    cout<<tree_size[i]<< " ";
        dist_sum[0] = level_order(0, adj, visited1);
        level_order1(N, 0, adj, visited2, dist_sum, tree_size);
        vector<int> res(dist_sum, dist_sum + N);
        return res;
    }
};