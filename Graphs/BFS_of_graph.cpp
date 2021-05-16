class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	   vector<int> bfs;
	   int visited[V];
	   memset(visited, 0, sizeof(visited));

	   queue<int> q;
	   q.push(0);
	   visited[0] = 1;

	   while(!q.empty()){
	       int size = q.size();
	       while(size > 0){
	           int curr = q.front();
	           q.pop();
	           bfs.push_back(curr);

	           for(auto i : adj[curr]){
	               if(!visited[i]){
	                   q.push(i);
	                   visited[i] = 1;
	               }
	           }
			   
	           size--;
	       }
	   }
	   return bfs;
	}
};