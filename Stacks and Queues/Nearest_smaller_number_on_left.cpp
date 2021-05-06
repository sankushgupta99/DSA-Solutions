class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        vector<int> res;
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && s.top() >= a[i])
                s.pop();
            
            if(s.empty()){
                res.push_back(-1);
                s.push(a[i]);
            }
            else{
                res.push_back(s.top());
                s.push(a[i]);
            }
        }
        return res;
    }
};