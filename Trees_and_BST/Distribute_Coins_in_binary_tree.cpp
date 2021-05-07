class Solution {
public:
    int distributeCoinsUtil(TreeNode* root, int &cost){
        if(root == NULL)
            return 0;
        
        int left_cost = distributeCoinsUtil(root->left, cost);
        int right_cost = distributeCoinsUtil(root->right, cost);
        
        cost += (abs(left_cost) + abs(right_cost));
        
        return left_cost + right_cost + root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        int cost = 0;
        distributeCoinsUtil(root, cost);
        return cost;
    }
};

//OR

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