class Solution {
public:
    void DFS(map<string, priority_queue<string, vector<string>, greater<string>>> &adj, string src, vector<string> &itenary){
        while(!adj[src].empty()){
            string v = adj[src].top();
            adj[src].pop();
            DFS(adj, v, itenary);
        }
        itenary.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for(auto i : tickets){
            string u = i[0];
            string v = i[1];
            adj[u].push(v);
        }
        
        vector<string> itenary;
        DFS(adj, "JFK", itenary);
        reverse(itenary.begin(), itenary.end());
        return itenary;
    }
};

//OR

class Solution {
public:
    void DFS(map<string, priority_queue<string, vector<string>, greater<string>>> &adj, string src, stack<string> &s){
        while(!adj[src].empty()){
            string v = adj[src].top();
            adj[src].pop();
            DFS(adj, v, s);
        }
        s.push(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for(auto i : tickets){
            string u = i[0];
            string v = i[1];
            adj[u].push(v);
        }
        
        stack<string> s;
        DFS(adj, "JFK", s);
        
        vector<string> itenary;
        while(!s.empty()){
            itenary.push_back(s.top());
            s.pop();
        }
        return itenary;
    }
};