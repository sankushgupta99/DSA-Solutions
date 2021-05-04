void preorder(Node* root, map<int,vector<int>> &m, int level){
    if(root == NULL)
    return;
    
    m[level].push_back(root->data);
    
    preorder(root->left, m, level + 1);
    preorder(root->right, m, level);
}

vector<int> diagonal(Node *root)
{
   vector<int> res;
   
   if(root == NULL)
   return res;
   
   map<int, vector<int>> m;
   
   preorder(root, m, 0);
   
   map<int,vector<int>>::iterator it;
   for(it = m.begin(); it != m.end(); it++){
       for(int i = 0; i < it->second.size(); i++){
           res.push_back(it->second[i]);
       }
   }
   return res;
}