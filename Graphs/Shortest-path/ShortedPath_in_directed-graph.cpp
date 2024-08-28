vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        //create adjacency list
        int n=N;
        vector<vector<int>>adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        
        vector<int>dist(n,1e9);
        dist[0]=0;
        
        
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto it:adj[node]){
                int adjnode=it[0];
                int dis=it[1];
                if(dis+dist[node]<dist[adjnode]){
                    dist[adjnode]=dis+dist[node];
                    q.push(adjnode);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }