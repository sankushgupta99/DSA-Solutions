class Solution {
public:
    TreeNode* sortedArrayToBSTUtil(vector<int>& nums, int l, int r){
        if(l > r)
            return NULL;
        
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = sortedArrayToBSTUtil(nums, l, mid - 1);
        root->right = sortedArrayToBSTUtil(nums, mid + 1, r);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTUtil(nums, 0, nums.size() - 1);
    }
};