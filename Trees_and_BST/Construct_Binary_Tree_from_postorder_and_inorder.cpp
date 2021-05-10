class Solution {
public:
    map<int, int> occurence;
    
    TreeNode* generate_tree(vector<int> postorder, int ps, int pe, vector<int> inorder, int is, int ie){
        if(ps > pe || is > ie)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        int idx = occurence[postorder[pe]];
        int count = idx - is;
        
        root->left = generate_tree(postorder, ps, ps + count - 1, inorder, is, idx - 1);
        root->right = generate_tree(postorder, ps + count, pe - 1, inorder, idx + 1, ie);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0)
            return NULL;
        
        for(int i = 0; i < inorder.size(); i++){
            occurence[inorder[i]] = i;
        }
        
        return generate_tree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
    }
};