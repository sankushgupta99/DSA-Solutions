class Solution {
public:
    int l, r;
    int subtree_size(TreeNode* root, int x){
        if(root == NULL)
            return 0;
        
        int left = subtree_size(root->left, x);
        int right = subtree_size(root->right, x);
        
        if(root->val == x){
            l = left; r = right;
        }
        
        return left + right + 1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        subtree_size(root, x);
        int max_score = max(n-l-r-1, max(l, r));
        return max_score > (n / 2);
    }
};

//OR

class Solution {
public:
    TreeNode* find(TreeNode* root, int x){
        if(root == NULL)
            return NULL;
        
        if(root->val == x)
            return root;
        
        TreeNode* left = find(root->left, x);
        TreeNode* right = find(root->right, x);
        
        if(left != NULL)
            return left;
        else
            return right;
    }
    
    int subtree_size(TreeNode* curr){
        if(curr == NULL)
            return 0;
        
        return subtree_size(curr->left) + subtree_size(curr->right) + 1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* x_node = find(root, x);
        
        int left_tree_size = subtree_size(x_node->left);
        int right_tree_size = subtree_size(x_node->right);
        int rem_tree_size = n - 1 - left_tree_size - right_tree_size;
        
        int max_score = max(rem_tree_size, max(left_tree_size, right_tree_size));
        if(max_score > (n/2))
            return true;
        else
            return false;
    }
};