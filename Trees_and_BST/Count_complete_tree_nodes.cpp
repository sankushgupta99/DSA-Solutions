class Solution {
public:
    int left_height(TreeNode* root){
        int height = 1;
        
        while(root->left != NULL){
            height++;
            root = root->left;
        }
        
        return height;
    }
    
    int right_height(TreeNode* root){
        int height = 1;
        
        while(root->right != NULL){
            height++;
            root = root->right;
        }
        
        return height;
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int lh = left_height(root);
        int rh = right_height(root);
        
        if(lh == rh){
            return (1 << lh) - 1;
        }
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};