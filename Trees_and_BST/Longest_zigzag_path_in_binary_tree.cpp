class Solution {
public:
    int ZigZag(TreeNode* root, bool is_left, int &max_l){
        if(root == NULL)
            return 0;
        
        int left = ZigZag(root->left, 1, max_l);
        int right = ZigZag(root->right, 0, max_l);
        
        max_l = max(max_l, max(left, right));
        
        if(is_left == 1)
            return right + 1;
        else
            return left + 1;
    }
    
    int longestZigZag(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int max_length = 0;
        int left = ZigZag(root->left, 1, max_length);
        int right = ZigZag(root->right, 0, max_length);
        max_length = max(max_length, max(left, right));
        
        return max_length;
    }
};