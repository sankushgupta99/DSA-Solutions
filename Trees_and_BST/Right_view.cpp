class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightview;
        if(root == NULL)
            return rightview;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                TreeNode* curr = q.front();
                q.pop();
                if(size == 1){
                    rightview.push_back(curr->val);
                }
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
                size--;
            }
        }
        return rightview;
    }
};