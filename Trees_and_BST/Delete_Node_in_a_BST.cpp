class Solution {
public:
    TreeNode* delete_Util(TreeNode* root){
        if(root == NULL)
            return root;
        
        if(root->left == NULL && root->right == NULL)
            return NULL;
        else if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;
        else{
            TreeNode* temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;
            temp->left = root->left;
            return root->right;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            root = delete_Util(root);
        }
        return root;
    }
};

//OR

class Solution {
public:
    TreeNode* delete_Util(TreeNode* root){
        if(root == NULL)
            return root;
        
        if(root->left == NULL && root->right == NULL)
            return NULL;
        else if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;
        else{
            TreeNode* temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;
            swap(temp->val, root->val);
            root->right = deleteNode(root->right, temp->val);
            return root;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            root = delete_Util(root);
        }
        return root;
    }
};