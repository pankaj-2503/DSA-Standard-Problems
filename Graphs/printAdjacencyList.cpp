 vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>>ans(V);
        int n=edges.size();
        for(int i=0;i<n;i++){
            auto p=edges[i];
            ans[p.first].push_back(p.second);
            ans[p.second].push_back(p.first);
        }
        
        return ans;
    }