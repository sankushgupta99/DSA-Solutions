vector<int> reverseLevelOrder(Node *root)
{
    vector<int> res;
    
    if(root == NULL)
    return res;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        while(size > 0){
            Node* curr = q.front();
            q.pop();
            res.push_back(curr->data);
            
            if(curr->right != NULL)
            q.push(curr->right);
            if(curr->left != NULL)
            q.push(curr->left);
            
            size--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}