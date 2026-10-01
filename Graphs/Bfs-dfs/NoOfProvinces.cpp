class Solution {
public:
// Time Complexity: O(N*N) + O(V+2E) , Space Complexity: O(N) + O(N)
    void dfs(int i,vector<vector<int>>&adj,vector<int>&visited){
        visited[i]=1;
        for(auto j:adj[i]){
            if(!visited[j]){
                dfs(j,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<vector<int>>adj(v);
        vector<int>visited(v,0);
        //converting into adjacency list from adjacent matrix
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<v;i++){
            if(visited[i]==0){
                cnt++;
                dfs(i,adj,visited);
            }
        }
        return cnt;
    }
};





// TC -> O(N^2*alpha(n))
class dsu{
    public:
    vector<int>rank,parent;
    dsu(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);

    }

    void unionbyrank(int u,int v){
        int ult_u=findUPar(u);
        int ult_v=findUPar(v);
        if(ult_u==ult_v) return;
        if(rank[ult_u]<rank[ult_v]) parent[ult_u]=ult_v;
        else if(rank[ult_v]>rank[ult_u]) parent[ult_v]=ult_u;
        else{
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
    }


};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        dsu d(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1) d.unionbyrank(i,j);
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(d.findUPar(i)==i) cnt++;
        }
        return cnt;
    }
};