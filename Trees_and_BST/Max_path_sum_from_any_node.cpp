class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSumUtil(Node* root, int &omax){
        if(root == NULL)
        return 0;
        int leftsum = findMaxSumUtil(root->left, omax);
        int rightsum = findMaxSumUtil(root->right, omax);
        int temp = max(root->data,max(leftsum, rightsum)+ root->data);
        int res = max(temp, leftsum+rightsum+root->data);
        omax = max(omax, res);
        return temp;
    }
    int findMaxSum(Node* root)
    {
        int omax = -10010;
        findMaxSumUtil(root, omax);
        return omax;
    }
};