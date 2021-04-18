bool isBalanced_util(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return 1;
    }
    
    int l;
    int r;
    int lr;
    int rr;
    
    lr = isBalanced_util(root->left, &l);
    rr = isBalanced_util(root->right, &r);
    
    *height = 1 + max(l, r);
    
    if(abs(l - r) >= 2)
    return 0;
    
    return lr && rr;
}
bool isBalanced(Node *root)
{
    int h;
    return isBalanced_util(root, &h);
}

// OR
int height(Node* root){
    if(root == NULL)
    return 0;
    
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(Node *root)
{
    if(root == NULL)
    return 1;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh - rh) >= 2)
    return false;
    
    return isBalanced(root->left) && isBalanced(root->right);
}
