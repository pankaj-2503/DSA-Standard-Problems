// Time complexity - O(n*alpha(n))
class dsu{
    public:
        vector<int>rank,parent;
        dsu(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++) parent[i]=i;
        }

        int findupar(int node){
            if(node==parent[node]) return node;
            return parent[node]=findupar(parent[node]);
        }

        void unionbyrank(int u,int v){
            int ultu=findupar(u);
            int ultv=findupar(v);
            if(ultu==ultv) return;
            if(rank[ultu]<rank[ultv]) parent[ultu]=ultv;
            else if(rank[ultv]<rank[ultu]) parent[ultv]=ultu;
            else {
                parent[ultv]=ultu;
                rank[ultu]++;
            }
        }



};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu d(n);
        for(int i=0;i<n;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            if(d.findupar(a)==d.findupar(b)) return edges[i];
            d.unionbyrank(a,b);
        }
        return {};
    }
};