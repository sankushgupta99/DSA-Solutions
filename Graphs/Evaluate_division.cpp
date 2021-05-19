#define psd pair<string,double>
class Solution {
public:
    void DFS(map<string, vector<psd>> adj, string src, string dest, map<string, int> &visited, double ans, int &flag, double &final_ans){
        visited[src] = 1;
        if(src == dest){
            flag++;
            final_ans = ans;
        }
        for(auto i : adj[src]){
            string node = i.first;
            double weight = i.second;
            if(visited.find(node) == visited.end()){
                if(!flag){
                    DFS(adj, node, dest, visited, ans * weight, flag, final_ans);
                }
            }
        }
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        map<string, vector<psd>> adj;
        vector<double> ans;
        
        for(int i = 0; i < equations.size(); i++){
            string node1 = equations[i][0];
            string node2 = equations[i][1];
            double val = values[i]; 
            adj[node1].push_back({node2, val});
            adj[node2].push_back({node1, 1.0 / val});
        }
        
        for(int i = 0; i < queries.size(); i++){
            string src = queries[i][0];
            string dest = queries[i][1];
            if(adj.find(src) == adj.end() || adj.find(dest) == adj.end()){
                ans.push_back(-1.0);
                continue;
            }
            
            map<string, int> visited;
            int flag = 0;
            double answer;
            DFS(adj, src, dest, visited, 1.0, flag, answer);
            if(flag){
                ans.push_back(answer);
            }
            else{
                ans.push_back(-1.0);
            }
        }
        
        return ans;
    }
};