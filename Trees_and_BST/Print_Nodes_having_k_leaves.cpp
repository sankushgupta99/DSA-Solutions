class Solution{
  public:
    /*You are required to complete below method */
    int traversal(Node* root, int k, vector<int> &res){
        if(root == NULL)
        return 0;
        
        else if(root->left == NULL && root->right == NULL){
            return 1;
        }
        
        int left = traversal(root->left, k, res);
        int right = traversal(root->right, k, res);
        
        if(left + right == k){
            res.push_back(root->data);
        }
        
        return left + right;
    }
    
    vector<int> btWithKleaves(Node *ptr, int k)
    { 
        vector<int> res;
        traversal(ptr, k, res);
        
        if(res.size() == 0)
            res.push_back(-1);
            
        return res;
    }

};