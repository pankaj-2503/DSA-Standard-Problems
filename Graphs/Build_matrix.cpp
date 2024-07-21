class Solution {
public:
// Time complexity ~ O(K^2) , space complexity ~ O(K^2)
    vector<int>topoSort(vector<vector<int>>&graph,int k){
        vector<int>indegree(k+1,0);
        for(int i=1;i<=k;i++){
            for(auto j:graph[i]){
                indegree[j]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:graph[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(ans.size()==k) return ans;
        else return {};
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // what comes to mind is that we have to order numbers according to appearance
        // we could use topo sort , which would return array with condition satisfying
        // create map  to store index where to store in original array

        // adjacency list creation to operate topo sort
        vector<vector<int>>rowGraph(k+1),colGraph(k+1);
        for(auto i:rowConditions){
            rowGraph[i[0]].push_back(i[1]);
        }
        for(auto i:colConditions){
            colGraph[i[0]].push_back(i[1]);
        }

        // store ans from topo sort
        vector<int>rowOrder=topoSort(rowGraph,k);
        vector<int>colOrder=topoSort(colGraph,k);
        if(rowOrder.empty() || colOrder.empty()) return {};

        vector<vector<int>>result(k,vector<int>(k,0));
        // creating mapping for each k 
        unordered_map<int,int>rowMap,colMap;
        for(int i=0;i<k;i++){
            rowMap[rowOrder[i]]=i;
            colMap[colOrder[i]]=i;
        }

        for(int i=1;i<=k;i++){
            result[rowMap[i]][colMap[i]]=i;
        }

        return result;



    }
};