class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> res;
        res.push_back(a[n-1]);
        int max_el = a[n-1];
        
        for(int i = n - 2; i >= 0; i--){
            if(a[i] >= max_el)
                res.push_back(a[i]);
            max_el = max(max_el, a[i]);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};