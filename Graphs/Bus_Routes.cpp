class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        map<int, vector<int>> m;
        int bus_vis[routes.size()];
        int busstop_vis[100010];
        
        for(int i = 0; i < routes.size(); i++){
            for(int j : routes[i]){
                m[j].push_back(i);
            }
        }
        
        memset(bus_vis, 0, sizeof(bus_vis));
        memset(busstop_vis, 0, sizeof(busstop_vis));
        
        queue<pair<int, int>> q;
        q.push({source, 0});
        busstop_vis[source] = 1;
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                pair<int, int> p = q.front();
                q.pop();
                
                if(p.first == target){
                    return p.second;
                }
                
                vector<int> buses = m[p.first];
                for(int i : buses){
                    if(!bus_vis[i]){
                        bus_vis[i] = 1;
                        for(int j : routes[i]){ 
                            if(!busstop_vis[j]){
                                q.push({j, p.second + 1});
                                busstop_vis[j] = 1;
                            }
                        }
                    }
                }
                size--;
            }
        }
        return -1;
    }
};

//OR

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        map<int, vector<int>> m;
        int bus_vis[routes.size()];
        int busstop_vis[100010];
        
        for(int i = 0; i < routes.size(); i++){
            for(int j = 0; j < routes[i].size(); j++){
                m[routes[i][j]].push_back(i);
            }
        }
        
        memset(bus_vis, 0, sizeof(bus_vis));
        memset(busstop_vis, 0, sizeof(busstop_vis));
        
        queue<pair<int, int>> q;
        q.push(make_pair(source, 0));
        busstop_vis[source] = 1;
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                pair<int, int> p = q.front();
                q.pop();
                
                if(p.first == target){
                    return p.second;
                }
                
                vector<int> buses = m[p.first];
                for(int i = 0; i < buses.size(); i++){
                    if(!bus_vis[buses[i]]){
                        bus_vis[buses[i]] = 1;
                        
                        for(int j = 0; j < routes[buses[i]].size(); j++){
                            int bus_stop = routes[buses[i]][j];
                            
                            if(!busstop_vis[bus_stop]){
                                q.push(make_pair(bus_stop, p.second + 1));
                                busstop_vis[bus_stop] = 1;
                            }
                            
                        }
                        
                    }
                }
                
                size--;
            }
        }
        return -1;
    }
};