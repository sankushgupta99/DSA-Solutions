class Solution{
  public:
    void add_clone_nodes(Node* root){
        if(root == NULL)
        return;
        
        Node* clone_node = new Node(root->data);
        clone_node->left = root->left;
        root->left = clone_node;
        
        add_clone_nodes(root->left->left);
        add_clone_nodes(root->right);
    }
    
    void assign_random(Node* root){
        if(root == NULL)
        return;
        
        if(root->random != NULL)
        root->left->random = root->random->left;
        
        assign_random(root->left->left);
        assign_random(root->right);
    }
    
    Node* segregate_trees(Node* root){
        if(root == NULL)
        return NULL;
        
        Node* left_ret = segregate_trees(root->left->left);
        Node* right_ret = segregate_trees(root->right);
        
        Node* temp = root->left;
        root->left = root->left->left;
        temp->left = left_ret;
        temp->right = right_ret;
        
        return temp;
    }
    
    Node* cloneTree(Node* tree)
    {
       add_clone_nodes(tree);
       assign_random(tree);
       return segregate_trees(tree);
    }
};