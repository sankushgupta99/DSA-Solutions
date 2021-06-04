class Solution 
{
    public:
    int par[101];
    
    int find(int x){
        if(par[x] == x)
        return x;
        
        int temp = find(par[x]);
        par[x] = temp;
        return temp;
    }
    
    void unionSet(int x, int y){
        int lox = find(x);
        int loy = find(y);
        
        par[lox] = loy;
    }
    
    static bool sortByProfit(Job a, Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, sortByProfit);
        for(int i = 0; i <= 100; i++){
            par[i] = i;
        }
        
        int max_profit = 0;
        int job_count = 0;
        
        for(int i = 0; i < n; i++){
            if(find(arr[i].dead) != 0){
                job_count++;
                max_profit += arr[i].profit;
                int u = find(arr[i].dead);
                unionSet(u, u - 1);
            }
        }
        return {job_count, max_profit};
    } 
};