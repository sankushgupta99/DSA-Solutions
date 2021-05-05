class Solution {
public:
    long long max_prod = 0;
    long long totalSum(TreeNode* root){
        if(root == NULL)
            return 0;
        
        return totalSum(root->left) + totalSum(root->right) + root->val;
    }
    long long maxProductUtil(TreeNode* root, int total_sum){
        if(root == NULL)
            return 0;
        
        long long left = maxProductUtil(root->left, total_sum);
        long long right = maxProductUtil(root->right, total_sum);
        long long subtree_sum = left + right + root->val;
        
        if(subtree_sum * (total_sum - subtree_sum) > max_prod)
            max_prod = subtree_sum * (total_sum - subtree_sum);
        
        return subtree_sum;
    }
    int maxProduct(TreeNode* root) {
        long long total_sum = totalSum(root);
        maxProductUtil(root, total_sum);
        return max_prod % 1000000007;
    }
};