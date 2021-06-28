class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        stack<char> stack1;
        stack1.push(s[0]);
        
        for(int i = 1; i < n; i++){
             if(!stack1.empty() && s[i] == stack1.top()){
                 stack1.pop();
             }
             else{
                 stack1.push(s[i]);
             }
        }
        
        string res;
        while(!stack1.empty()){
            res += stack1.top();
            stack1.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};