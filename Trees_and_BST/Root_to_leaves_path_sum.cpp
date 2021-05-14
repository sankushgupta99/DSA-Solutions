long long PathSumUtil(Node* root, int value){
    if(root == NULL)
    return 0;
    
    if(root->left == NULL && root->right == NULL){
        return ((value * 10) + root->data);
    }
    
    long long left = PathSumUtil(root->left, (value * 10) + root->data);
    long long right = PathSumUtil(root->right, (value * 10) + root->data);
    return left + right;
}

long long treePathsSum(Node *root)
{
    return PathSumUtil(root, 0);
}

//OR

class Solution {
public:
    int total_sum = 0;
    
    void sum_util(TreeNode* root, int value){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL){
            total_sum += ((value * 10) + root->val);
            return;
        }
        
        sum_util(root->left, (value * 10) + root->val);
        sum_util(root->right, (value * 10) + root->val);
    }
    
    int sumNumbers(TreeNode* root) {
        sum_util(root, 0);
        return total_sum;
    }
};