#define ll long long
class Solution {
public:
    static bool sortByDecEff(pair<int,int> &a, pair<int,int> &b){
        return (a.second > b.second);
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> engineers;
        for(int i = 0; i < n; i++){
            engineers.push_back({speed[i], efficiency[i]});
        }
        
        sort(engineers.begin(), engineers.end(), sortByDecEff);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(engineers[0].first);
        ll sum = engineers[0].first;
        ll max_performance = sum * engineers[0].second;
        
        for(int i = 1; i < n; i++){
            int s = engineers[i].first;
            int e = engineers[i].second;
            pq.push(s);
            sum += s;
            
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            
            max_performance = max(max_performance, sum * e);
        }
        return (max_performance % 1000000007);
    }
};