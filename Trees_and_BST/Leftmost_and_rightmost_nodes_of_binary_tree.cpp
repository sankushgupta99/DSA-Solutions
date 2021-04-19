void printCorner(Node *root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 1; i <= size; i++){
            Node* curr = q.front();
            q.pop();
            if(i == 1 || i == size){
                cout<< curr->data <<" ";
            }
            if(curr->left != NULL)
            q.push(curr->left);
            if(curr->right != NULL)
            q.push(curr->right);
        }
    }

}