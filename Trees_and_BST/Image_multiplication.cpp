#define mod 1000000007
class Solution
{
    public:
    void calculateProdSum(Node* root1, Node* root2, long long &prod_sum){
        if(root1 == NULL || root2 == NULL){
            return;
        }
        
        prod_sum = (prod_sum + (root1->data * root2->data)) % mod;
        
        calculateProdSum(root1->left, root2->right, prod_sum);
        calculateProdSum(root1->right, root2->left, prod_sum);
    }
    
    long long imgMultiply(Node *root)
    {
        long long prod_sum = 0;
        
        if(root == NULL)
        return prod_sum;
        
        prod_sum = (prod_sum + (root->data * root->data)) % mod;
        
        calculateProdSum(root->left, root->right, prod_sum);
        return prod_sum;
    }
};