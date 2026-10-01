// TC -> O(E*4alpha(V)) , SC -> O(V)
class dsu{
    // Time complexity is O(4*alpha)
    vector<int> rank, parent;
    int component;
public:
    dsu(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        component=n;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        component--;
    }
    int getComponent(){
        return component;
    }
};

// Idea is that keep type 3 edges as it's beneficial in both alice,bob
// keep seperate edges for type 1, type 2 and check if fully traversable then remove from total edges - kept_edges

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu alice(n);
        dsu bob(n);
        int edge_kept=0;
        // basically we are adding type 3 edge to both dsu of alice,bob seperately
        for(auto &edge:edges){

            int u=edge[1];
            int v=edge[2];
            int type=edge[0];
            int cnt=0;
            if(type==3){
                if(alice.findUPar(u)!=alice.findUPar(v)){
                    alice.unionByRank(u,v);
                    cnt++;
                }
                if(bob.findUPar(u)!=bob.findUPar(v)){
                    bob.unionByRank(u,v);
                    cnt++;
                }
                // if any one of them get used cnt it
                if(cnt>0){
                    edge_kept++;
                }
            }
        }
    // cnt eges that they both have of original type 1,2 and connecting them
        for(auto &edge:edges){
            int u=edge[1],v=edge[2];
            int type=edge[0];
            if(type==1){
                if(alice.findUPar(u)!=alice.findUPar(v)){
                    alice.unionByRank(u,v);
                    edge_kept++;
                }
            }else if(type==2){
                if(bob.findUPar(u)!=bob.findUPar(v)){
                    bob.unionByRank(u,v);
                    edge_kept++;
                }
            }
        }
    // if traversable then it would have become 1 component
        if(alice.getComponent()==1 && bob.getComponent()==1){
            return edges.size()-edge_kept;
        }
        return -1;







    }
};