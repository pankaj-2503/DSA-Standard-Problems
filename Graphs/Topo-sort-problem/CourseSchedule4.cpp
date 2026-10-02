class Solution {
public:
// tC -> O(N^3+Q) , SC - O(N^2)
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<bool>>isvalid(n,vector<bool>(n,false));
        for(auto &pre:prerequisites){
            isvalid[pre[0]][pre[1]]=true;
        }
        //floyd-warshall for transitive closure
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(isvalid[i][k] && isvalid[k][j]){
                        isvalid[i][j]=true; // since a-b , b-c,then a-c
                    }
                }
            }
        }
        int q=queries.size();
        vector<bool>ans(q,false);
        for(int i=0;i<q;i++){
            ans[i]=isvalid[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
};


// Kahn's algor


class Solution {
public:
// tC -> O((V+E) + V*(V+E) + Q) , SC -> O(V^2 +E +Q)
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n =numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        // Build adjacency list

        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        // ancestors[v] stores all prerequisites(direct+indirect)
        vector<unordered_set<int>>ancestors(n);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int j:adj[node]){
                //direct prerequisites
                ancestors[j].insert(node);
                //indirect prerequisite
                ancestors[j].insert(ancestors[node].begin(),ancestors[node].end());

                indegree[j]--;
                if(indegree[j]==0) q.push(j);
            }
        }

        int v=queries.size();
        vector<bool>ans(v);
        for(int i=0;i<v;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            // here checking if u is ancestor of v or not
            ans[i]=ancestors[v].count(u)>0;
        }
        return ans;
    }
};