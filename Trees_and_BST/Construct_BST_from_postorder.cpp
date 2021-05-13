Node* constructBST(int post[], int min, int max, int &i){
    if(i < 0 || post[i] < min || post[i] > max){
        return NULL;
    }
    
    Node* root = new Node(post[i--]);
    
    root->right = constructBST(post, root->data + 1, max, i);
    root->left = constructBST(post, min, root->data - 1, i);
    
    return root;
}

Node *constructTree (int post[], int size)
{
    int i = size - 1;
    return constructBST(post, INT_MIN, INT_MAX, i);
}