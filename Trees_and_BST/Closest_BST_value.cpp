class Solution {
public:
    double min_abs_val;
    int ans;
    void closestValueUtil(TreeNode* root, double target){
        if(root == NULL)
            return;

        if(abs(root->val - target) < min_abs_val){
            min_abs_val = abs(root->val - target);
            ans = root->val;
        }

        if(target < root->val)
            closestValueUtil(root->left, target);
        else
            closestValueUtil(root->right, target);
    } 

    int closestValue(TreeNode * root, double target) {
        min_abs_val = INT_MAX;
        closestValueUtil(root, target);
        return ans;
    }
};