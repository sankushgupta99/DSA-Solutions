class Solution {
public:
    TreeNode* build(int n, ListNode* &temp){
        if(n == 0)
            return NULL;
        
        TreeNode* left = build(n/2, temp);
        
        TreeNode* root = new TreeNode();
        root->val = temp->val;
        root->left = left;
        temp = temp->next;
        
        TreeNode* right = build(n-(n/2)-1, temp);
        
        root->right = right;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int node_count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            node_count++;
            temp = temp->next; 
        }
        temp = head;
        return build(node_count, temp);
    }
};