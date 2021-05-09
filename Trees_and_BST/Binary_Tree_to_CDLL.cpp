class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    void merge_CDLL(Node* tail1, Node* tail2){
        Node* head1 = tail1->right;
        Node* head2 = tail2->right;
        
        tail1->right = head2;
        head2->left = tail1;
        
        tail2->right = head1;
        head1->left = tail2;
    }
    Node* bTreeToCDLL(Node* root){
        if(root == NULL)
        return root;
        
        Node* left_tail = bTreeToCDLL(root->left);
        Node* right_tail = bTreeToCDLL(root->right);
        
        if(root->left == NULL && root->right == NULL){
            root->left = root;
            root->right = root;
            return root;
        }
        else if(root->left == NULL){
            root->left = root;
            root->right = root;
            merge_CDLL(root, right_tail);
            return right_tail;
        }
        else if(root->right == NULL){
            root->left = root;
            root->right = root;
            merge_CDLL(left_tail, root);
            return root;
        }
        else{
            root->left = root;
            root->right = root;
            merge_CDLL(left_tail, root);
            merge_CDLL(root, right_tail);
            return right_tail;
        }
    }
    Node *bTreeToCList(Node *root)
    {
        if(root == NULL)
        return root;
        
        Node* tail = bTreeToCDLL(root);
        return tail->right;
    }
};