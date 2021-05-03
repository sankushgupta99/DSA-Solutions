// 1) If conflicts need to be resolved according to the order in which nodes come in level order traversal
class Solution
{
    public:
    vector<int> verticalOrder(Node *root)
    {
        vector<int> res;
        
        if(root == NULL)
        return res;
        
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        map<int, vector<int>> m;
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                Node* curr = q.front().first;
                int curr_node_level = q.front().second;
                q.pop();
                
                m[curr_node_level].push_back(curr->data);
                
                if(curr->left != NULL){
                    q.push(make_pair(curr->left, curr_node_level - 1));
                }
                if(curr->right != NULL){
                    q.push(make_pair(curr->right, curr_node_level + 1));
                }
                size--;
            }
        }
        map<int, vector<int>>::iterator it;
        for(it = m.begin(); it != m.end(); it++){
            for(int i = 0; i < it->second.size(); i++){
                res.push_back(it->second[i]);
            }
        }
        return res;
    }
};

// 2) If conflicts need to be resolved first on the basis of horizontal level and then value of the nodes
class Solution {
public:
    static bool sortUtil(pair<int,int> a, pair<int,int> b){
        if(a.second != b.second){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        
        if(root == NULL)
            return res;
        
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        map<int,vector<pair<int,int>>> m;
        int level = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                TreeNode* curr = q.front().first;
                int curr_node_level = q.front().second;
                q.pop();
                
                m[curr_node_level].push_back(make_pair(curr->val,level));
                
                if(curr->left != NULL){
                    q.push(make_pair(curr->left, curr_node_level - 1));
                }
                if(curr->right != NULL){
                    q.push(make_pair(curr->right, curr_node_level + 1));
                }
                
                size--;
            }
            level++;
        }
        
        map<int,vector<pair<int,int>>>::iterator it;
        for(it = m.begin(); it != m.end(); it++){
            sort(it->second.begin(), it->second.end(), sortUtil);
            vector<int> temp;
            for(int i = 0; i < it->second.size(); i++){
                temp.push_back(it->second[i].first);
            }
            res.push_back(temp);
        }
        
        return res;
    }
};