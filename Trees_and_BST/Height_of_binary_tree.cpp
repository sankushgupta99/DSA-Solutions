class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        queue<Node*> q;
        q.push(node);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            while(size > 0){
                Node* curr = q.front();
                q.pop();
                if(curr->left != NULL)
                q.push(curr->left);
                if(curr->right != NULL)
                q.push(curr->right);
                size--;
            }
        }
        return level;
    }
};