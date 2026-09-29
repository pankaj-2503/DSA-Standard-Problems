

#define ll long long
class Solution {
public:
    // TC-> O((E)log(v)) , sC -> O(V+E)
    int countPaths(int n, vector<vector<int>>& roads) {
        ll mod=1e9+7;
        vector<vector<pair<ll,ll>>>adj(n);
        for(int i=0;i<roads.size();i++){
            ll u=roads[i][0];
            ll v=roads[i][1];
            ll w=roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<ll>dist(n,1e18);
        vector<ll>ways(n,0);

        dist[0]=0;
        ways[0]=1;



        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0}); // {dist,src node}

        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();

            // it means if there are other ways to reach u and has higher cost just ignore them as it can't contribute to shorted path
            if(d>dist[u]) continue;

            for(auto &neighbor:adj[u]){
                int v=neighbor.first;
                int w=neighbor.second;

                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                    ways[v]=ways[u];
                }else if(w+dist[u]==dist[v]){
                    // it means same shortest distance again encountered
                    ways[v]=(ways[v]%mod + ways[u]%mod)%mod;
                }
            }

        }

        return ways[n-1]%mod;


    }
};





// Bellman ford  -> tC - Total = O(V * E) + O(E) + O(V + E) = O(V * E)


#include <vector>

using namespace std;

class Solution {
    int MOD = 1e9 + 7;

    long long dfs(int u, int n, const vector<vector<pair<int, long long>>>& adj, const vector<long long>& dist, vector<long long>& memo) {
        if (u == n - 1) return 1;
        if (memo[u] != -1) return memo[u];

        long long ways = 0;
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;

            // Only traverse edges that are part of the shortest path
            if (dist[u] + w == dist[v]) {
                ways = (ways + dfs(v, n, adj, dist, memo)) % MOD;
            }
        }
        return memo[u] = ways;
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n, 1e18); // Use 1e18 to prevent overflow when adding
        dist[0] = 0;

        // Bellman-Ford: Relax all edges n-1 times
        for (int i = 0; i < n - 1; ++i) {
            bool updated = false;
            for (const auto& road : roads) {
                int u = road[0], v = road[1];
                long long w = road[2];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
                if (dist[v] + w < dist[u]) {
                    dist[u] = dist[v] + w;
                    updated = true;
                }
            }
            // Early exit if no distances were updated in this pass
            if (!updated) break;
        }

        // Build adjacency list for counting ways
        vector<vector<pair<int, long long>>> adj(n);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> memo(n, -1);
        return dfs(0, n, adj, dist, memo);
    }
};



// Floyd warshall -> TC - Total = O(V^2 + E) + O(V^3) + O(V + E) = O(V^3)


#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int MOD = 1e9 + 7;

    long long dfs(int u, int n, const vector<vector<long long>>& distMatrix, const vector<vector<pair<int, long long>>>& adj, vector<long long>& memo) {
        if (u == n - 1) return 1;
        if (memo[u] != -1) return memo[u];

        long long ways = 0;
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;

            // Check if the edge u -> v is on the shortest path from 0 to v
            if (distMatrix[0][u] + w == distMatrix[0][v]) {
                ways = (ways + dfs(v, n, distMatrix, adj, memo)) % MOD;
            }
        }
        return memo[u] = ways;
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<long long>> distMatrix(n, vector<long long>(n, 1e18));
        vector<vector<pair<int, long long>>> adj(n);

        for (int i = 0; i < n; ++i) {
            distMatrix[i][i] = 0;
        }

        // Populate Adjacency List (for DFS) & Adjacency Matrix (for FW)
        for (const auto& road : roads) {
            int u = road[0], v = road[1];
            long long w = road[2];
            distMatrix[u][v] = w;
            distMatrix[v][u] = w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (distMatrix[i][k] == 1e18) continue;
                for (int j = 0; j < n; ++j) {
                    if (distMatrix[k][j] == 1e18) continue;
                    if (distMatrix[i][k] + distMatrix[k][j] < distMatrix[i][j]) {
                        distMatrix[i][j] = distMatrix[i][k] + distMatrix[k][j];
                    }
                }
            }
        }

        vector<long long> memo(n, -1);
        return dfs(0, n, distMatrix, adj, memo);
    }
};