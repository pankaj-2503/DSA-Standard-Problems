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