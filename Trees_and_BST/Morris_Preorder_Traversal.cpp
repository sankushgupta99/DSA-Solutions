vector <int> preorder(Node* root)
{
    vector<int> res;
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            res.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* currp1 = curr->left;
            while(currp1->right != NULL && currp1->right != curr){
                currp1 = currp1->right;
            }
            if(currp1->right == NULL){
                res.push_back(curr->data);
                currp1->right = curr;
                curr = curr->left;
            }
            else{
                currp1->right = NULL;
                curr = curr->right;
            }
        }
    }
    return res;
}