class DisjointSet{
    vector<int>parent,size,rank;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<n;i++){
            parent[i]=i; // node itself parent
        }

    }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ult_u=findUPar(u);
        int ult_v=findUPar(v);
        if(ult_u==ult_v) return ;
        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else if(rank[ult_u]>rank[ult_v]){
            parent[ult_v]=ult_u;
        }
        else{
            parent[ult_v]=ult_u;
        }
    }
};
// Time complexity - O(N^2)
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        DisjointSet dsu(4*n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int root=4*(i*n+j);
                char value=grid[i][j];
                if(value=='/'){
                    dsu.unionByRank(root+0,root+3);
                    dsu.unionByRank(root+1,root+2);
                }else if(value=='\\'){
                    dsu.unionByRank(root+0,root+1);
                    dsu.unionByRank(root+2,root+3);
                }
                else{
                    // empty cases
                    dsu.unionByRank(root+0,root+1);
                    dsu.unionByRank(root+1,root+2);
                    dsu.unionByRank(root+2,root+3);
                }
                // union right neighbouring cell
                if(j+1<n){
                    dsu.unionByRank(root+1,root+7);
                }
                // union below neighbouring cell
                if(i+1<n){
                    dsu.unionByRank(root+2,root+4*n);
                }
            }
            
        }
        int region=0;
        for(int i=0;i<4*n*n;i++){
            if(dsu.findUPar(i)==i) region++;
        }
        return region;
    }
};