class Solution
{
    public: 
    void merge(Node* tail1, Node* tail2){
        Node* head1 = tail1->right;
        Node* head2 = tail2->right;
        tail1->right = head2;
        head2->left = tail1;
        tail2->right = head1;
        head1->left = tail2;
    }
    Node* bToDLLUtil(Node* root){
        if(root == NULL)
        return root;
        
        Node* left_ret = bToDLLUtil(root->left);
        Node* right_ret = bToDLLUtil(root->right);
        
        if(root->left == NULL && root->right == NULL){
            root->left = root;
            root->right = root;
            return root;
        }
        else if(root->left == NULL){
            root->left = root;
            root->right = root;
            merge(root, right_ret);
            return right_ret;
        }
        else if(root->right == NULL){
            root->left = root;
            root->right = root;
            merge(left_ret, root);
            return root;
        }
        else{
            root->left = root;
            root->right = root;
            merge(left_ret, root);
            merge(root, right_ret);
            return right_ret;
        }
    }
    
    Node * bToDLL(Node *root)
    {
        Node* tail = bToDLLUtil(root);
        Node* head = tail->right;
        head->left = NULL;
        tail->right = NULL;
        return head;
    }
};