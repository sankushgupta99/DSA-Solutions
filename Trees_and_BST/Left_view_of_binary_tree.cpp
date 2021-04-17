vector<int> leftView(Node *root)
{
    vector<int> leftview;
    if(root == NULL)
    return leftview;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       int size = q.size();
       int level_node_count = size;
       while(size > 0){
           Node* curr = q.front();
           q.pop();
           if(size == level_node_count){
               leftview.push_back(curr->data);
           }
           if(curr->left != NULL)
           q.push(curr->left);
           if(curr->right != NULL)
           q.push(curr->right);
           size--;
       }
   }
   return leftview;
}