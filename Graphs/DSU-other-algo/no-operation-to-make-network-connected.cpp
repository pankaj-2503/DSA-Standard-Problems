    // Time complexity is O(N+E*4*alpha)
class dsu {
    vector<int> rank, parent,size;
public:
    dsu(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1,0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
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
    }

     void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    //  To connect all disconnected components, you need $(\text{number of components}) - 1$ operations (using redundant cables)
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        dsu d(n);
        int extracable=0;
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            if(d.findUPar(a)==d.findUPar(b)) extracable++;
            d.unionByRank(a,b);
        }

        int component=0;
        for(int i=0;i<n;i++){
            if(d.findUPar(i)==i) component++;
        }
        int need=component-1;
        return (extracable>=need)?need:-1;


    }
};