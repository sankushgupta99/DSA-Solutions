class Solution{
public:
    int eulerPath(int N, vector<vector<int>> graph){
        int degree[N];
        memset(degree, 0, sizeof(degree));
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(graph[i][j])
                degree[j]++;
            }
        }
        
        int even_deg_nodes = 0;
        for(int i = 0; i < N; i++){
            if(degree[i] % 2 == 0)
                even_deg_nodes++;
        }
        
        if(even_deg_nodes == N || even_deg_nodes == N-2)
            return 1;
        else
            return 0;
    }
};
