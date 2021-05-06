void traverse(Node* root, vector<int> &res){
    if(root == NULL)
    return;
    
    if(root->left != NULL && root->right == NULL)
    res.push_back(root->left->data);
    
    if(root->left == NULL && root->right != NULL)
    res.push_back(root->right->data);
    
    traverse(root->left, res);
    traverse(root->right, res);
}
vector<int> noSibling(Node* root)
{
    vector<int> res;
    traverse(root, res);
    
    sort(res.begin(), res.end());
    
    if(res.size() == 0)
    res.push_back(-1);
    
    return res;
}