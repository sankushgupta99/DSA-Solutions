class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int fuel = startFuel;
        priority_queue<int> pq;
        int stop_count = 0;
        
        for(auto& i : stations){
            int dist = i[0];
            int gas_vol = i[1];
            
            if(fuel >= dist){
                pq.push(gas_vol);
                continue;
            }
            
            while(!pq.empty() && fuel < dist){
                fuel += pq.top();
                pq.pop();
                stop_count++;
            }
            
            if(fuel < dist)
                return -1;
            
            pq.push(gas_vol);
        }
        
        while(!pq.empty() && fuel < target){
            fuel += pq.top();
            pq.pop();
            stop_count++;
        }
        
        return (fuel < target) ? -1 : stop_count;
    }
};