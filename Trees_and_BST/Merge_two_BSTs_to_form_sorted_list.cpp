class Solution
{
    public:
    void traversal(Node* root, vector<int> &v){
        if(root == NULL)
        return;
        traversal(root->left, v);
        v.push_back(root->data);
        traversal(root->right, v);
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> v1, v2, v3;
       traversal(root1, v1);
       traversal(root2, v2);
       int i = 0, j = 0;
       while(i < v1.size() && j < v2.size()){
           if(v1[i] < v2[j]){
               v3.push_back(v1[i]);
               i++;
           }
           else if(v2[j] < v1[i]){
               v3.push_back(v2[j]);
               j++;
           }
           else{
               v3.push_back(v1[i]);
               v3.push_back(v2[j]);
               i++; j++;
           }
       }
       while(i < v1.size()){
           v3.push_back(v1[i]);
           i++;
       }
       while(j < v2.size()){
           v3.push_back(v2[j]);
           j++;
       }
       return v3;
    }
};