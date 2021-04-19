class Solution
{
    public:
    bool isSumTreeUtil(Node* root, int *sum){
        if(root == NULL){
            *sum = 0;
            return true;
        }
        int l_sum = 0;
        int r_sum = 0;
        bool l_ans;
        bool r_ans;
        
        l_ans = isSumTreeUtil(root->left, &l_sum);
        r_ans = isSumTreeUtil(root->right, &r_sum);
        
        *sum = root->data + l_sum + r_sum;
        
        if(root->left == NULL && root->right == NULL)
        return true;
        
        if(root->data != l_sum + r_sum)
        return false;
        
        return l_ans && r_ans;
    }
    bool isSumTree(Node* root)
    {
        int sum;
        return isSumTreeUtil(root, &sum);
    }
};