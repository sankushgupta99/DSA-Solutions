int countLeaves(Node* root)
{
    if(root == NULL)
    return 0;
    if(root->right == NULL && root->left == NULL)
    return 1;
  
    return countLeaves(root->left) + countLeaves(root->right);
}