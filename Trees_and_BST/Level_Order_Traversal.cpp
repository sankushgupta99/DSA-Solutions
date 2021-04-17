class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      queue<Node*> q;
      q.push(node);
      vector<int> res;
      while(!q.empty()){
          int size = q.size();
          while(size>0){
              Node* curr = q.front();
              q.pop();
              res.push_back(curr->data);
              if(curr->left != NULL){
                  q.push(curr->left);
              }
              if(curr->right != NULL){
                  q.push(curr->right);
              }
              size--;
          }
      }
      return res;
    }
};