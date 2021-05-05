int countSubtreesWithSumXUtil(Node* root, int X, int &count){
    if(root == NULL)
    return 0;
    
    int left_sum = countSubtreesWithSumXUtil(root->left, X, count);
    int right_sum = countSubtreesWithSumXUtil(root->right, X, count);
    int subtree_sum = left_sum + right_sum + root->data;
    
    if(subtree_sum == X)
    count++;
    
    return subtree_sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
	int count = 0;
	countSubtreesWithSumXUtil(root, X, count);
	return count;
}
