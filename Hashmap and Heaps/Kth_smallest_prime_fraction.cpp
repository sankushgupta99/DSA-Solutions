#define pdp pair<double, pair<int, int>>
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pdp, vector<pdp>, greater<pdp>> pq;
        
        for(int i = 0; i < n-1; i++){
            pq.push({((double)arr[i] / arr[n-1]), {i, n-1}});
        }
        
        int i, j;
        while(k){
            pdp curr = pq.top(); pq.pop(); 
            i = curr.second.first;
            j = curr.second.second;
            if(i < j-1)
                pq.push({((double)arr[i] / arr[j-1]), {i, j-1}});
            k--;
        }
        
        return {arr[i], arr[j]};
    }
};

//OR

#define vi vector<int>
class Solution {
public:
    struct compare{
        bool operator()(const vi& a, const vi& b){
            return (a[2] * b[3] > a[3] * b[2]);
        }
    };
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<vi, vector<vi>, compare> pq;
        
        for(int i = 0; i < n-1; i++){
            pq.push({i, n-1, arr[i], arr[n-1]});
        }
        
        int count = 0;
        while(!pq.empty()){
            vector<int> curr = pq.top(); pq.pop(); count++;
            int i = curr[0];
            int j = curr[1];
            
            if(count == k)
                return {arr[i], arr[j]};
            
            if(i < j-1)
                pq.push({i, j-1, arr[i], arr[j-1]});
        }
        
        return {};
    }
};

//OR

#define vi vector<int>
class Solution {
public:
    struct compare{
        bool operator()(const vi& a, const vi& b){
            return (a[2] * b[3] > a[3] * b[2]);
        }
    };
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<vi, vector<vi>, compare> pq;
        
        for(int i = 0; i < n-1; i++){
            pq.push({i, n-1, arr[i], arr[n-1]});
        }
        
        int i, j;
        while(k){
            vector<int> curr = pq.top(); pq.pop(); 
            i = curr[0];
            j = curr[1];
            if(i < j-1)
                pq.push({i, j-1, arr[i], arr[j-1]});
            k--;
        }
        
        return {arr[i], arr[j]};
    }
};