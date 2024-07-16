class Solution {
public:
// Time Complexity: O(V+E) , Space Complexity: O(N) + O(N) ~ O(2N)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v=numCourses;
        vector<int>adj[v];
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++) if(indegree[i]==0) q.push(i);

        vector<int>res;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto j:adj[node]){
                indegree[j]--;
                if(indegree[j]==0) q.push(j);
            }
        }
        if(res.size()==v) return res;
        else return {};
        
    }
};