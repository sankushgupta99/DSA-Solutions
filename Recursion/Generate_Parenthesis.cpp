class Solution {
public:
    void generateUtil(int n, int ind, int open_count, string &str, vector<string> &res){
        if(ind == 2*n){
            if(open_count == 0)
                res.push_back(str);
            return;
        }
        
        if(open_count != 0){
            string temp = str;
            str += ")";
            generateUtil(n, ind + 1, open_count - 1, str, res);
            str = temp;
        }
        
        generateUtil(n, ind + 1, open_count + 1, str += "(", res);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        generateUtil(n, 0, 0, str, res);
        return res;
    }
};