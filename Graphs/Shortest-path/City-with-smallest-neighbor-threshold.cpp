
class Solution {
public:
    // TC -> O(N^3) , SC -> O(N^2)
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) mat[i][j]=0;
            }
        }

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            mat[u][v]=min(mat[u][v],w);
            mat[v][u]=min(mat[v][u],w);
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        map<int,int>m;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]!=1e9 && mat[i][j]<=distanceThreshold) cnt++;
            }
            m[i]=cnt;
            mn=min(mn,cnt);
        }
        int ans=0;
        for(auto i:m){
            if(i.second==mn) ans=i.first;
        }

        return ans;

    }
};


// Modified dijkstra 

class Solution {
public:
    // Time complexity - > O(N*Elog(N)) , SC -> O(N+E)

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Build adjacency list

        vector<vector<pair<int,int>>>adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }

        int mn=n;
        int ans=-1;

        // run dijkstra from each city
        for(int i=0;i<n;i++){
            vector<int>dist(n,1e9);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

            dist[i]=0;
            pq.push({0,i});

            while(!pq.empty()){
                auto [d,u] = pq.top();
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

            int cnt=0;
            for(int j=0;j<n;j++){
                if(j!=i && dist[j]<=distanceThreshold) cnt++;
            }

            if(cnt<=mn){
                mn=cnt;
                ans=i;
            }



        }

        return ans;


    }
};


