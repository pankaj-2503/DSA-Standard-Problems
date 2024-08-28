 
 // Time complexity - O(N+2E) ,space complexity - O(N) 
 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        int visited[V+1]={0};
        int i=0;
            if(!visited[i]){
                queue<int>q;
                q.push(i);
                visited[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    ans.push_back(node);
                    for(auto j:adj[node]){
                       if(!visited[j]){
                           q.push(j);
                        visited[j]=1;
                       } 
                    }
                }
            }
        
        return ans;
    }