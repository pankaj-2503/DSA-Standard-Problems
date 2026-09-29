class Solution {
    public:
    // Time complexity - > O(Elog(v)) , SC -> O(V+E)

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int,double>>>graph(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double p= succProb[i];
            // since undirected
            graph[u].push_back({v,p});
            graph[v].push_back({u,p});
        }

        priority_queue<pair<double,int>>pq; // max pq to process highes probability

        vector<double>max_prob(n,0.0);
        max_prob[start_node]=1.0;
        pq.push({1.0,start_node});

        while(!pq.empty()){
            auto [cur_prob,u] = pq.top();
            pq.pop();

            if(u==end_node) return cur_prob;
            if(cur_prob<max_prob[u]) continue;

            for(auto &edge:graph[u]){
                int v=edge.first;
                double p=edge.second;

                if(cur_prob*p>max_prob[v]){
                    max_prob[v]=cur_prob*p;
                    pq.push({max_prob[v],v});
                }
            }
        }

        return 0.0;
    }
};


// Bellman ford -> TC - O(v*e) , SC -> O(V)
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>maxprob(n,0.0);
        maxprob[start_node]=1.0;

        // Relax n-1 times
        for(int i=0;i<n-1;i++){
            bool updated=false;
            for(int j=0;j<edges.size();j++){
                int u=edges[j][0];
                int v=edges[j][1];
                double p=succProb[j];

                  // Relax u->v
                if(maxprob[u]*p>maxprob[v]){
                    maxprob[v]=maxprob[u]*p;
                    updated=true;
                }
                // Relax v->u as undirected graph
                if(maxprob[v]*p>maxprob[u]){
                    maxprob[u]=maxprob[v]*p;
                    updated=true;
                }
            }
            if(!updated) break;

        }

        return maxprob[end_node];
    }
};



// Floyd Warshall algo

class Solution {
public:
    // Time complexity - O(V^3) , sC -> O(V^2)
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<double>>prob(n,vector<double>(n,0.0));

        for(int i=0;i<n;i++) prob[i][i]=1.0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succProb[i];

            prob[u][v]=max(prob[u][v],p);
            prob[v][u]=max(prob[v][u],p);
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    prob[i][j]=max(prob[i][j],prob[i][k]*prob[k][j]);
                }
            }
        }

        return prob[start_node][end_node];
    }
};