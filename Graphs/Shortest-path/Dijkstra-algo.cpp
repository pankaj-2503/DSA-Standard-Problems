//   Time Complexity : O( E log(V) , Space Complexity : O( |E| + |V| ) 
  vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
       set<pair<int,int>> st; 

        
        vector<int> dist(V, 1e9); 
        
        st.insert({0, S}); 

        // Source initialised with dist=0
        dist[S] = 0;
        
        while(!st.empty()) {
            auto it = *(st.begin()); 
            int node = it.second; 
            int dis = it.first; 
            st.erase(it); 
            
          
            for(auto it : adj[node]) {
                int adjNode = it[0]; 
                int edgW = it[1]; 
                
                if(dis + edgW < dist[adjNode]) {
                    // erase if it was visited previously at 
                    // a greater cost.
                    if(dist[adjNode] != 1e9) 
                        st.erase({dist[adjNode], adjNode}); 
                        
                    // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 
                 }
            }
        }
      
        return dist; 
    }

    // priority -queue implementation
    class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(V,1e9);
        dis[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            auto it=pq.top();
           pq.pop();
            
            int d=it.first;
            int node=it.second;
            for(auto it:adj[node]){
                int d2=d+it[1];
                int node2=it[0];
                
                if(dis[node2]>d2){
                    dis[node2]=d2;
                    pq.push({d2,node2});
                }
            }
        }
        return dis;
        
    }
};