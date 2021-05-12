class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    Node* traversal(Node* root, int K, int &curr){
        if(root == NULL)
        return NULL;
        
        Node* left = traversal(root->left, K, curr);
        if(left != NULL)
        return left;
        
        curr++;
        if(curr == K)
        return root;
        
        Node* right = traversal(root->right, K, curr);
        return right;
    }
    int KthSmallestElement(Node *root, int K)
    {
        int curr = 0;
        Node* kth_smallest = traversal(root, K, curr);
        
        if(kth_smallest == NULL)
        return -1;
        
        return kth_smallest->data;
    }
};