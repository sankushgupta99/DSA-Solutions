vector<int> findSpiral(Node *root)
{
    vector<int> res;
    if(root == NULL)
    return res;
    stack<Node*> s1;
    stack<Node*> s2;
    s2.push(root);
    int level = 0;
    while(!s1.empty() || !s2.empty()){
        level++;
        if(level % 2 == 0){
            int size = s1.size();
            while(size>0){
                Node* curr = s1.top();
                s1.pop();
                res.push_back(curr->data);
                if(curr->left != NULL){
                    s2.push(curr->left);
                }
                if(curr->right != NULL){
                    s2.push(curr->right);
                }
                size--;
            }
        }
        else{
            int size = s2.size();
            while(size>0){
                Node* curr = s2.top();
                s2.pop();
                res.push_back(curr->data);
                if(curr->right != NULL){
                    s1.push(curr->right);
                }
                if(curr->left != NULL){
                    s1.push(curr->left);
                }
                size--;
            }
        }
    }
    return res;
}