class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        int visited[n];
        memset(visited, 0, sizeof(visited));
        
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            if(arr[curr] == 0)
                return true;
                
            int ind1 = curr + arr[curr];
            int ind2 = curr - arr[curr];
            
            if(ind1 >= 0 && ind1 < n && !visited[ind1]){
                q.push(ind1);
                visited[ind1] = 1;
            }
            if(ind2 >= 0 && ind2 < n && !visited[ind2]){
                q.push(ind2);
                visited[ind2] = 1;
            }
        }
        
        return false;
    }
};