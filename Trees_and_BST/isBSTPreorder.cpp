class Solution {
public:
    bool isBSTUtil(TreeNode* root, long long int min, long long int max){
        if(root == NULL)
            return true;
        
        if(root->val < min || root->val > max)
            return false;
        
        long long int new_max = root->val;
        new_max--;
        long long int new_min = root->val;
        new_min++;
        
        return isBSTUtil(root->left, min, new_max) && isBSTUtil(root->right, new_min, max);
    }
    bool isValidBST(TreeNode* root) {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};