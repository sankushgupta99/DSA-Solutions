#define pip pair<int, pair<int, int>>
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pip,vector<pip>,greater<pip>> pq;
        
        for(int i = 0; i < n; i++){
            pq.push({matrix[i][0], {i, 0}});
        }
        
        int count = 0;
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop(); count++;
            int i = curr.second.first;
            int j = curr.second.second;
            
            if(count == k)
                return matrix[i][j];
            
            if(j + 1 < n)
                pq.push({matrix[i][j+1], {i, j + 1}});
        }
        
        return -1;
    }
};