class Solution {
public:
    void inorder(TreeNode* root, double target, int k, queue<int> &q){
        if(root == NULL)
        return;

        inorder(root->left, target, k, q);

        if(q.size() < k){
            q.push(root->val);
        }
        else{
            if(abs(target - root->val) < abs(q.front() - target)){
                q.pop();
                q.push(root->val);
            }
        }

        inorder(root->right, target, k, q);
    }
    vector<int> closestKValues(TreeNode * root, double target, int k) {
       queue<int> q;
       vector<int> res;
       inorder(root, target, k, q);

       while(!q.empty()){
           res.push_back(q.front());
           q.pop();
       }

       return res;
    }
};