class Solution {
public:
    map<int,int> occurence;
    
    TreeNode* generate_tree(vector<int> preorder, int ps, int pe, vector<int> inorder, int is, int ie){
        if(ps > pe || is > ie)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[ps]);
        int idx = occurence[preorder[ps]];
        int count = idx - is;
        
        root->left = generate_tree(preorder, ps + 1, ps + count, inorder, is, idx - 1);
        root->right = generate_tree(preorder, ps + count + 1, pe, inorder, idx + 1, ie);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return NULL;
        
        for(int i = 0; i < inorder.size(); i++){
            occurence[inorder[i]] = i;
        }
        
        return generate_tree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};