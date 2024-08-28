class Solution {
public:
// Time Complexity: O(N) + O(V+2E) , Space Complexity: O(N) + O(N)
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