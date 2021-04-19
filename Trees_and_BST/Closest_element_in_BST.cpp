class Solution
{
    public:
    int minDiff(Node *root, int K)
    {
        if(root == NULL)
        return INT_MAX;
        
        int sub_ans = INT_MAX;
        
        if(K > root->data){
            sub_ans = minDiff(root->right, K);
        }
        else if(K < root->data){
            sub_ans = minDiff(root->left, K);
        }
        return min(sub_ans, abs(K - root->data));
    }
};