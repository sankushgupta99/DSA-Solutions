class Solution
{
    public:
    void preorder(Node* root, vector<int> &v1){
        if(root == NULL){
            v1.push_back(-1);
            return;
        }
        
        v1.push_back(root->data);
        
        preorder(root->left, v1);
        preorder(root->right, v1);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int> v1;
        preorder(root, v1);
        return v1;
    }
    
    Node* preorder2(vector<int> &A, int &i){
        if(A[i] == -1)
        {
            i++;
            return NULL;
        }
        
        Node* root = new Node(A[i++]);
        
        root->left = preorder2(A, i);
        root->right = preorder2(A, i);
        
        return root;
    }
    Node* deSerialize(vector<int> &A)
    {
       int i = 0;
       return preorder2(A, i);
    }

};