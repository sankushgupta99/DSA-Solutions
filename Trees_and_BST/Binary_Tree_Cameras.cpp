class Solution {
public:
    int minCameraUtil(TreeNode* root, int &cost){
        if(root == NULL)
            return 2;
        
        int left_ret = minCameraUtil(root->left, cost);
        int right_ret = minCameraUtil(root->right, cost);
        
        if(right_ret == 0 || left_ret == 0){
            cost++;
            return 1;
        }
        else if(right_ret == 1 || left_ret == 1)
            return 2;
        else
            return 0;
    }
    int minCameraCover(TreeNode* root) {
        int cost = 0;
        int ret = minCameraUtil(root, cost);
        if(ret == 0)
            cost++;
        return cost;
    }
};