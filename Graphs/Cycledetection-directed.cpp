 bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathvis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true) return true;
            }
        }
        return false;
    }
    bool dfs(int node,vector<int>adj[],int vis[],int pathvis[]){
        vis[node]=1;
        pathvis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true) return true;
            }
            else if(pathvis[i]) return true;
        }
        pathvis[node]=0;
        return false;
    }