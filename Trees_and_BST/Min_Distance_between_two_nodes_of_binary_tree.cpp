Node* LCA(Node* root, int a, int b, int &d1, int &d2, int &d3, int level){
    if(root == NULL)
    return NULL;
    
    if(root->data == a){
        d1 = level;
    }
    if(root->data == b){
        d2 = level;
    }
    
    Node* left = LCA(root->left, a, b, d1, d2, d3, level + 1);
    Node* right = LCA(root->right, a, b, d1, d2, d3, level + 1);
    
    if(left == NULL && right == NULL){
        if(root->data == a || root->data == b){
            return root;
        }
        else{
            return NULL;
        }
    }
    else if(left == NULL){
        if(root->data == a || root->data == b){
            d3 = level;
            return root;
        }
        else{
            return right;
        }
    }
    else if(right == NULL){
        if(root->data == a || root->data == b){
            d3 = level;
            return root;
        }
        else{
            return left;
        }
    }
    else{
        d3 = level;
        return root;
    }
    
}
int findDist(Node* root, int a, int b) {
    int d1, d2, d3;
    LCA(root, a, b, d1, d2, d3, 0);
    return d1 + d2 - (2 * d3);
}

//OR

int DistFromRoot(Node* curr, int a, int dist){
    if(curr == NULL)
    return -1;
    
    int left = DistFromRoot(curr->left, a, dist + 1);
    if(left != -1)
    return left;
    
    if(curr->data == a){
        return dist;
    }
    
    int right = DistFromRoot(curr->right, a, dist + 1);
    return right;
}

Node* LCA(Node* root, int a, int b){
    if(root == NULL)
    return NULL;
    
    Node* left = LCA(root->left, a, b);
    Node* right = LCA(root->right, a, b);
    
    if(left == NULL && right == NULL){
        if(root->data == a || root->data == b)
            return root;
        else
            return NULL;
    }
    else if(left == NULL){
        if(root->data == a || root->data == b)
            return root;
        else
            return right;
        
    }
    else if(right == NULL){
        if(root->data == a || root->data == b)
            return root;
        else
            return left;
    }
    else{
        return root;
    }
}
int findDist(Node* root, int a, int b) {
    int d1 = DistFromRoot(root, a, 0);
    int d2 = DistFromRoot(root, b, 0);
    
    Node* lca = LCA(root, a, b);
    int lca_dist = DistFromRoot(root, lca->data, 0);
    
    return d1 + d2 - (2 * lca_dist);
}