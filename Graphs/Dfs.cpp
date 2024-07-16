 // Time complexity - O(N+2E) ,space complexity - O(N) 
 vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<int>visited(V+1,0);
        int i=0;
        if(!visited[i]) dfs(i,adj,ans,visited);
        return ans;
    }
    void dfs(int node,vector<int>adj[],vector<int>&ans,vector<int>&visited){
        visited[node]=1;
        ans.push_back(node);
        for(auto j:adj[node]){
            if(!visited[j]) dfs(j,adj,ans,visited);
        }
    }