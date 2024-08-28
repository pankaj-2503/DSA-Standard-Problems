class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1]; // since node labelled as 1 to n
        for(auto i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//{dist,node}
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int weight=pq.top().first;
            pq.pop();

            for(auto it:adj[node]){
                int adjnode=it.first;
                int adjwt=it.second;
                if(adjwt+weight<dist[adjnode]){
                    dist[adjnode]=adjwt+weight;
                    pq.push({weight+adjwt,adjnode});
                }
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9 && i!=k) return -1;
            mx=max(mx,dist[i]);
        }
        return mx;
    }
};