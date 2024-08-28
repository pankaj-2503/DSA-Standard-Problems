class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        queue<pair<int,pair<int,int>>>q;// {stops,node,dist}
        vector<int>dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it=q.front();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            q.pop();
            if(stops>k) continue;
            for(auto i:adj[node]){
                int adjnode=i.first;
                int adjcost=i.second;
                if(adjcost+cost<dist[adjnode] && stops<=k){
                      dist[adjnode]=adjcost+cost;
                      q.push({stops+1,{adjnode,adjcost+cost}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        else return dist[dst];

    }
};