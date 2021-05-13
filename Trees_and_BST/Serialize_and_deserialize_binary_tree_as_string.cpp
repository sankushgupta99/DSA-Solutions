class Codec {
public:

    void preorder(TreeNode* root, string &s){
        if(root == NULL){
            s += "null,";
            return;
        }
        
        int value = root->val;
        string s1;
        if(value < 0){
            s += "-";
            value *= -1;
        }
        
        while(value > 0){
            s1 += ((value % 10) + 48);
            value /= 10;
        }
        
        reverse(s1.begin(), s1.end());
        s += s1;
        s += ",";
        
        preorder(root->left, s);
        preorder(root->right, s);
    }
    
    string serialize(TreeNode* root) {
        string serialized_string;
        preorder(root, serialized_string);
        return serialized_string;
    }
    
    TreeNode* preorder2(string s, int &i){
        string curr;
        while(s[i] != ','){
            curr += s[i];
            i++;
        }
        i++;
        
        if(curr.compare("null") == 0)
            return NULL;
        
        int value = 0;
        for(int j = 0; j < curr.size(); j++){
            if(curr[j] != '-'){
                value = (value * 10) + (curr[j] - 48);
            }
        }
        
        if(curr[0] == '-')
            value *= -1;
        
        TreeNode* root = new TreeNode(value);
        root->left = preorder2(s, i);
        root->right = preorder2(s, i);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        int i = 0;
        return preorder2(data, i);
    }
};