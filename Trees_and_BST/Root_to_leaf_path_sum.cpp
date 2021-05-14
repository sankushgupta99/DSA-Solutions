class Solution
{
    public:
    bool hasPathSum(Node *root, int S) {
        if(root == NULL)
        return false;
        
        if(root->left == NULL && root->right == NULL && root->data == S)
        return true;
        
        return hasPathSum(root->left, S - root->data) || hasPathSum(root->right, S - root->data);
    }
};