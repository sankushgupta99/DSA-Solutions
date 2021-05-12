class Solution {
public:
    map<int, int> occurence;
    
    TreeNode* build(vector<int> pre, int pre_s, int pre_e, vector<int> post, int post_s, int post_e){
        if(pre_s > pre_e || post_s > post_e)
            return NULL;
        
        if(pre_s == pre_e){
            TreeNode* root = new TreeNode(post[post_e]);
            return root;
        }
        
        TreeNode* root = new TreeNode(post[post_e]);
        int idx = occurence[pre[pre_s + 1]];
        int count = idx - post_s + 1;
        
        root->left = build(pre, pre_s + 1, pre_s + count, post, post_s, idx);
        root->right = build(pre, pre_s + count + 1, pre_e, post, idx + 1, post_e - 1);
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.size() == 0)
            return NULL;
        
        for(int i = 0; i < post.size(); i++){
            occurence[post[i]] = i;
        }
        
        return build(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }
};