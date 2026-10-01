//Core idea: If index A can swap with B, and B can swap with C, then characters at A, B, and C can be rearranged in any order among those indices.
// Treat each index 0 .. n-1 as a node in a graph.Treat each pair [a, b] as an undirected edge between node a and node b.

class dsu{
    public:
    vector<int>rank,parent;
    dsu(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findupar(int node){
        if(node==parent[node]) return parent[node];
        return parent[node]=findupar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int ultu=findupar(u);
        int ultv=findupar(v);
        if(ultu==ultv) return;
        if(rank[ultu]<rank[ultv]) parent[ultu]=ultv;
        else if(rank[ultv]<rank[ultu]) parent[ultv]=ultu;
        else{
            parent[ultv]=ultu;
            rank[ultu]++;
        }
    }
};
// TC -> O(E*alpha(n)) , e is pair length and n is string length  , SC -> O(N+E)

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        dsu d(n);
        for(auto &p:pairs) d.unionbyrank(p[0],p[1]);

        // group indices and char by their component root
        unordered_map<int,vector<int>>componentIndices;
        unordered_map<int,vector<int>>componentchars;

        for(int i=0;i<n;i++){
            int root=d.findupar(i);
            componentIndices[root].push_back(i);
            componentchars[root].push_back(s[i]);
        }
        //sort char in each component and reconstruct the string
        for(auto &[root,indices]:componentIndices){
            auto &chars=componentchars[root];
            sort(chars.begin(),chars.end());

            for(int k=0;k<indices.size();k++){
                s[indices[k]]=chars[k];
            }
        }
        return s;
    }
};