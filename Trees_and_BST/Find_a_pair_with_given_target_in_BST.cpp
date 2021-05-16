class Solution{
  public:
    void merge(Node* tail1, Node* tail2){
        Node* head1 = tail1->right;
        Node* head2 = tail2->right;
        tail1->right = head2;
        head2->left = tail1;
        tail2->right = head1;
        head1->left = tail2;
    }
    Node* convertToDLL(Node* root){
        if(root == NULL)
        return root;
        
        Node* left_ret = convertToDLL(root->left);
        Node* right_ret = convertToDLL(root->right);
        
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
    int isPairPresent(struct Node *root, int target)
    {
        Node* tail = convertToDLL(root);
        Node* head = tail->right;
        
        while(tail != head){
            if(head->data + tail->data == target)
            return 1;
            
            if(head->data + tail->data < target)
            head = head->right;
            else
            tail = tail->left;
        }
        return 0;
    }
};