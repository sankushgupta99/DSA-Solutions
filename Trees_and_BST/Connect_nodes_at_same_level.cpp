class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        if(root == NULL)
        return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                Node* curr = q.front();
                q.pop();
                if(size > 1){
                    curr->nextRight = q.front();
                }
                if(curr->left != NULL)
                q.push(curr->left);
                if(curr->right != NULL)
                q.push(curr->right);
                size--;
            }
        }
        
    }    
      
};
