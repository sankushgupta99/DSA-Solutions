class Solution
{
    public:
    int sum = 0;
    void transformTree(struct Node *root)
    {
        if(root == NULL)
        return;
        transformTree(root->right);
        int val = root->data;
        root->data = sum;
        sum += val;
        transformTree(root->left);
    }
};