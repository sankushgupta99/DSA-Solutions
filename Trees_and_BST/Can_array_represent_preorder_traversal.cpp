struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution {
  public:
    Node* constructBST(int pre[], int min, int max, int &i, int N){
        if(i >= N || pre[i] < min || pre[i] > max){
            return NULL;
        }
        
        Node* root = new Node(pre[i++]);
        
        root->left = constructBST(pre, min, root->data, i, N);
        root->right = constructBST(pre, root->data, max, i, N);
        
        return root;
    }
    int canRepresentBST(int arr[], int N) {
        int i = 0;
        constructBST(arr, INT_MIN, INT_MAX, i, N);
        
        return (i == N ? 1 : 0);
    }
};