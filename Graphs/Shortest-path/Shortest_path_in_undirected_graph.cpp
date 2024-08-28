// Time complexity - O(N+2M) ,space complexity - O(N+M)
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        int n=N;
        //create adjacent list
        vector<int>adj[n];
        for(auto i:edges){
            //as undirected
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        // distance array
        int dist[n];
        for(int i=0;i<n;i++) dist[i]=1e9;
        dist[src]=0;
        
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto j:adj[node]){
                if(dist[node]+1<dist[j]){
                    dist[j]=dist[node]+1;
                    q.push(j);
                }
            }
        }
        
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(dist[i]!=1e9) ans[i]=dist[i];
        }
        return ans;
        
        
    }