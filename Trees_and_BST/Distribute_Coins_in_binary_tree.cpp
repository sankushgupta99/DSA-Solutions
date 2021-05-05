class Solution {
public:
    int distributeCoinsUtil(TreeNode* root, int &cost){
        if(root == NULL)
            return 0;
        
        int left = distributeCoinsUtil(root->left, cost);
        int right = distributeCoinsUtil(root->right, cost);
        int curr = left + right + root->val - 1;
        
        cost += abs(curr);
        return curr;
    }
    int distributeCoins(TreeNode* root) {
        int cost = 0;
        distributeCoinsUtil(root, cost);
        return cost;
    }
};