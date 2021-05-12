map<int, int> occurence;

Node* Build(int in[], vector<int> level, int is, int ie,int n){
    if(n == 0)
    return NULL;
    
    Node* root = new Node(level[0]);
    int idx = occurence[level[0]];
    int count = idx - is;
    vector<int> levelOrder_left;
    vector<int> levelOrder_right;
    for(int i = 1; i < n; i++){
        if(occurence[level[i]] < idx){
            levelOrder_left.push_back(level[i]);
        }
        else{
            levelOrder_right.push_back(level[i]);
        }
    }
    
    root->left = Build(in, levelOrder_left, is, idx - 1, count);
    root->right = Build(in, levelOrder_right, idx + 1, ie, n-1-count);
    
    return root;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    for(int i = 0; i < n; i++){
        occurence[inorder[i]] = i;
    }
    
    vector<int> levelorder;
    for(int i = 0; i < n; i++)
    levelorder.push_back(levelOrder[i]);
    
    return Build(inorder, levelorder, iStart, iEnd, n);
}