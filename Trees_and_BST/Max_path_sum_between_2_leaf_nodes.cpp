int maxPathSumUtil(Node* root, int &ans){
    if(root == NULL)
    return 0;
    int leftsum = maxPathSumUtil(root->left, ans);
    int rightsum = maxPathSumUtil(root->right, ans);
    int temp;
    if(root->left == NULL)
    temp = rightsum + root->data;
    else if(root->right == NULL)
    temp = leftsum + root->data;
    else
    temp = max(leftsum, rightsum) + root->data;
    if(root->left != NULL && root->right != NULL)
    ans = max(ans, rightsum + leftsum + root->data);
    return temp;
}
int maxPathSum(Node* root)
{ 
    int ans = -100010;
    maxPathSumUtil(root, ans);
    return ans;
}