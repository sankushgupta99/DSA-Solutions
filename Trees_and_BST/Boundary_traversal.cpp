void left_boundary(Node* root, vector<int> &res){
    if(root->left == NULL && root->right == NULL)
    return;
    
    res.push_back(root->data);
    
    if(root->left != NULL){
        left_boundary(root->left, res);
    }
    else{
        left_boundary(root->right, res);
    }
}

void leaves(Node* root, vector<int> &res){
    if(root == NULL)
    return;
    
    if(root->left == NULL && root->right == NULL){
        res.push_back(root->data);
        return;
    }
    leaves(root->left, res);
    leaves(root->right, res);
}

void right_boundary(Node* root, vector<int> &res){
    if(root->left == NULL && root->right == NULL)
    return;
    
    if(root->right != NULL){
        right_boundary(root->right, res);
    }
    else{
        right_boundary(root->left, res);
    }
    
    res.push_back(root->data);
}

vector<int> printBoundary(Node *root)
{
     vector<int> res;
     
     if(root == NULL)
     return res;
     
     res.push_back(root->data);
     
     if(root->left != NULL){
        left_boundary(root->left, res);
     }
     leaves(root, res);
     if(root->right != NULL){
        right_boundary(root->right, res);
     }
     
     return res;
}