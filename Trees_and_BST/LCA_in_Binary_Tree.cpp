class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left == NULL && right == NULL){
            if(root->val == p->val || root->val == q->val)
                return root;
            else
                return NULL;
        }
        else if(left == NULL){
            if(root->val == p->val || root->val == q->val)
                return root;
            else
                return right;
        }
        else if(right == NULL){
            if(root->val == p->val || root->val == q->val)
                return root;
            else
                return left;
        }
        else{
            return root;
        }
    }
};