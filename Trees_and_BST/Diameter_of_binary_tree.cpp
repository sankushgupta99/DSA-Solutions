class Solution
{
    public:
    //Function to return the diameter of a Binary Tree.
    int diameter_Util(Node* root, int &res){
        if(root == NULL)
        return 0;
        int left = diameter_Util(root->left, res);
        int right = diameter_Util(root->right, res);
        int temp = max(left, right) + 1;
        res = max(res, left + right + 1);
        return temp;
    }
    int diameter(Node* root)
    {
        int res = 0;
        diameter_Util(root, res);
        return res;
    }

};