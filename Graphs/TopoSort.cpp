class Solution{
    public:
    // This algo also known as Kahn's algo
    // Time Complexity: O(V+E)+O(V) , Space Complexity: O(2N) + O(N) ~ O(2N): O(2N)
    	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   
	    // created indegree array and marked all indegrees
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto j:adj[node]){
	            indegree[j]--;
	            if(indegree[j]==0) q.push(j);
	        }
	    }
	    return ans;
	    
	}
};