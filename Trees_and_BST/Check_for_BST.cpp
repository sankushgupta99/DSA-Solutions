class Solution
{
    public:
    bool isBSTUtil(Node* root, int min, int max){
        if(root == NULL)
        return true;
        if(root->data > max || root->data < min)
        return false;
        
        return isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max);
    }
    bool isBST(Node* root) 
    {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};