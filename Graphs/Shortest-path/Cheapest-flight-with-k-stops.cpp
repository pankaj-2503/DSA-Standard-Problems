// Time complexity -> O(K*E) , Sc -> O(N)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Bellman ford algorithm with k relaxation

        vector<int>dist(n,1e9); // min. cost to reach city i from src
        dist[src]=0;
        // perform k+1 edge relaxation
        for(int i=0;i<=k;++i){
            //update from temp such such any dist updated don't contribute directly in another vertex w8 for next cycle of relaxation
            vector<int>temp=dist;
            for(auto &f:flights){
                int u=f[0];
                int v=f[1];
                int price=f[2];

                if(dist[u]!=1e9 && dist[u]+price<temp[v]){
                    temp[v]=dist[u]+price;
                }
            }
            dist=temp;

        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};



// BFS approach

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

