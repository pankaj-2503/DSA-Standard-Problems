class Solution {
public:
    // Time complexity,SC - O(V+E)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        vector<vector<int>>reverseadj(n);
        vector<int>outdegree(n,0);
        for(int u=0;u<n;u++){
            for(auto v:graph[u]){
                reverseadj[v].push_back(u);
            }
            outdegree[u]=graph[u].size();
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();q.pop();
            ans.push_back(node);
            for(auto neighbor:reverseadj[node]){
                outdegree[neighbor]--;
                if(outdegree[neighbor]==0) q.push(neighbor);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};