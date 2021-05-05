class Solution {
public:
    TreeNode* last_left = NULL;
    TreeNode* inorderSuccessorUtil(TreeNode * root, TreeNode * p){
        if(root == p){
            return last_left;
        }
        else if(p->val < root->val){
            last_left = root;
            return inorderSuccessorUtil(root->left, p);
        }
        else{
            return inorderSuccessorUtil(root->right, p);
        }
    }

    TreeNode* inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(root == NULL)
        return root;

        if(p->right != NULL){
            TreeNode* temp = p->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            return temp;
        }
        else{
            return inorderSuccessorUtil(root, p);
        }
    }
};

//OR

class Solution {
public:
    TreeNode* last_left = NULL;
    TreeNode* inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(root == NULL){
            return root;
        }
        if(root == p){
            if(root->right != NULL){
                TreeNode* temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                return temp;
            }
            else{
                return last_left;
            }
        }
        if(p->val < root->val){
            last_left = root;
            inorderSuccessor(root->left, p);
        }
        else{
            inorderSuccessor(root->right, p);
        }
    }
};