#define ll long long
class Solution {
public:
    int x,x1,y1;
    bool dfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=true;
        for(auto i:adj[node]){
            if(i==x1 || i==y1) return true;
            if(!vis[i]){
                if(dfs(i,vis,adj)) return true;
            }
        }
        return false;
    }
    bool helper(int node1,int node2,vector<int>adj[]){
        vector<int>vis(x,0);
        if(dfs(node1,vis,adj)) return true;
        vis.resize(x,0);

        if(dfs(node2,vis,adj)) return true;
        return false;
    }
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n=circles.size();
        // we are assuming sides or rectangle as complete node 
        vector<int>adj[n+4];
        x=n+4,x1=n+1,y1=n+2; // here x1 and y1 are target nodes

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                // calculating euclidean distance and if less than r1+r2 then intersecting circles
                ll eudist=sqrt(pow(circles[i][0]-circles[j][0],2ll)+pow(circles[i][1]-circles[j][1],2ll));
                if(eudist<=(circles[i][2]+circles[j][2]+0ll)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // checking for edge b/w circle and rectangle corner
        for(int i=0;i<n;i++){
            int x=circles[i][0];
            int y=circles[i][1];
            int r=circles[i][2];
            // intersection with left
            if(x<=r){
                adj[i].push_back(n);
                adj[n].push_back(i);
            }
            // intersection with bottom
            if(y<=r){
                adj[i].push_back(n+1);
                adj[n+1].push_back(i);
            }
            // intersection with right
            if(X-x<=r){
                adj[i].push_back(n+2);
                adj[n+2].push_back(i);
            }
            if(Y-y<=r){
                adj[i].push_back(n+3);
                adj[n+3].push_back(i);
            }
        }
        // it means cutting of corner with cirles happened
        if(helper(n+3,n,adj)) return false; // starting point either n or n+3
            return true;
    }
};


// using dsu 
#define ll long long
class DisjointSet {
    // Time complexity is O(4*alpha)
    vector<int> rank, parent,size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

     void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        ll n=circles.size();
        DisjointSet dsu(n+2);

        for(int i=0;i<n;i++){
            ll x=circles[i][0];
            ll y=circles[i][1];
            ll r=circles[i][2];

            // touches top and left
            if(x-r<=0 || y+r>=Y){
                dsu.unionByRank(n,i);
            }
            // touches right and bottom
            if(x+r>=X || y-r<=0){
                dsu.unionByRank(n+1,i);
            }
            for(int j=0;j<i;j++){
                ll x1=circles[j][0];
                ll y1=circles[j][1];
                ll r1=circles[j][2];
                // checking distance between 2 circles
                
                if((x1-x)*(x1-x)+(y1-y)*(y1-y)<=((r1+r)*(r1+r))){
                    dsu.unionByRank(i,j);
                }
            }

        }

        return dsu.findUPar(n)!=dsu.findUPar(n+1);

    }
};