class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> res;
        
        if(root == NULL)
        return res;
        
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        map<int,Node*> m;
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                Node* curr = q.front().first;
                int curr_node_level = q.front().second;
                q.pop();
                
                if(m.find(curr_node_level) == m.end()){
                    m[curr_node_level] = curr;
                }
                
                if(curr->left != NULL)
                q.push(make_pair(curr->left, curr_node_level-1));
                if(curr->right != NULL)
                q.push(make_pair(curr->right, curr_node_level+1));
                
                size--;
            }
        }
        map<int,Node*>::iterator it;
        for(it = m.begin(); it != m.end(); it++){
            res.push_back(it->second->data);
        }
        
        return res;
    }
};