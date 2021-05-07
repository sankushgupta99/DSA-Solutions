class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
    void traverse(TreeNode* curr){
        if(curr == NULL)
            return;
        
        traverse(curr->left);
        
        if((prev != NULL) && (curr->val < prev->val)){
            if(first == NULL){
                first = prev;
                second = curr;
            }
            else{
                second = curr;
            }
        }
        prev = curr;
        
        traverse(curr->right);
    }
    void recoverTree(TreeNode* root) {
        traverse(root);
        swap(first->val, second->val);
    }
};