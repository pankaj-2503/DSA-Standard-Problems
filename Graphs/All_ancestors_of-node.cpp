class Solution {
public:
// Time complexity - O(N+E) , space complexity - O(N)
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<vector<int>>ans(n);
        vector<int>indegree(n,0);
        vector<set<int>>ancestors(n);

        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto it:adj[node]){
                ancestors[it].insert(node);
                // append ancestors of prev node into current node's ancestors
                for(auto j:ancestors[node]){
                    ancestors[it].insert(j);
                }
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
    
        for(int i=0;i<n;i++){
            ans[i]=vector<int>(ancestors[i].begin(),ancestors[i].end());
        }
        return ans;
    }
};