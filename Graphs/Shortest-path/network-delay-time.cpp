class Solution {
public:
    // TC -> O(Elog(V) + V+E) , sC-> O(V+E)
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        vector<vector<pair<int,int>>>adj(n+1);

        for(vector<int>vec:times){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k}); //{wt,node}

        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();

            if(d>dist[u]) continue;

            for(auto &neighbor:adj[u]){
                int v=neighbor.first;
                int w=neighbor.second;

                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }

        int mxtime=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            mxtime=max(mxtime,dist[i]);
        }
        return mxtime;





    }
};



// Using Bellman ford algo , tC -> O(V*E) , SC -> O(V+E)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);
        dist[k]=0;

        for(int i=1;i<n;i++){
            bool updated=false;
            for(auto &edge:times){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];

                if(dist[u]!=1e9 && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    updated=true;
                }
            }
            if(!updated) break;
        }

        
        int mxtime=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            mxtime=max(mxtime,dist[i]);
        }
        return mxtime;


    }
};


// floyd warshall
// Time Complexity: O(V^3).Space Complexity: O(V^2) for the distance matrix.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));

        for (int i = 1; i <= n; ++i) dist[i][i] = 0;
        for (const auto& edge : times) {
            dist[edge[0]][edge[1]] = edge[2];
        }

        // Floyd-Warshall Dynamic Programming
        for (int mid = 1; mid <= n; ++mid) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dist[i][mid] < 1e9 && dist[mid][j] < 1e9) {
                        dist[i][j] = min(dist[i][j], dist[i][mid] + dist[mid][j]);
                    }
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[k][i] == 1e9) return -1;
            maxTime = max(maxTime, dist[k][i]);
        }

        return maxTime;
    }
};