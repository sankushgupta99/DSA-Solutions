class Solution {
public:
    TreeNode* flattenUtil(TreeNode* root){
        if(root == NULL)
            return root;
        
        TreeNode* left_ret = flattenUtil(root->left);
        TreeNode* right_ret = flattenUtil(root->right);
        
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        else if(root->right != NULL && root->left == NULL){
            return right_ret;
        }
        else if(root->right == NULL && root->left != NULL){
            root->right = root->left;
            root->left = NULL;
            return left_ret;
        }
        else{
            TreeNode* temp = root->right;
            root->right = root->left;
            left_ret->right = temp;
            root->left = NULL;
            return right_ret;
        }
    }
    void flatten(TreeNode* root) {
        flattenUtil(root);
    }
};

//OR

class Solution
{
    public:
    Node* prev = NULL;
    void flatten(Node *root)
    {
        if(root == NULL)
        return;
        
        Node* left = root->left;
        Node* right = root->right;
        
        if(prev == NULL)
        prev = root;
        else
        prev->right = root;
        
        root->left = NULL;
        root->right = NULL;
        prev = root;
        
        flatten(left);
        flatten(right);
    }
};