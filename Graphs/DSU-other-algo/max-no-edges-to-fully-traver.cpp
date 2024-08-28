// Alice and Bob have an undirected graph of n nodes and three types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph

// union find class with Size & components
class UnionFind {
    vector<int> root, Size;
    int components;
public:
    //Constructor using initializer list
    UnionFind(int n): root(n+1), Size(n+1,1), components(n){
        iota(root.begin(), root.end(), 0);//[0,1,...,n]    
    }
    
    int Find(int x) {//Path Compression O(alpha(n))
        if (x==root[x]) 
            return x;
        return root[x] = Find(root[x]);
    }

    bool Union(int x, int y) { //Union by Size O(alpha(n))   
        x=Find(x), y=Find(y);
        
        if (x == y) return 0;
        
        if (Size[x] > Size[y]) {
            Size[x] +=Size[y];
            root[y] = x;
        } 
        else {
            Size[y] += Size[x];
            root[x] = y;
        }       
        components--;
        return 1;
    }

    bool isConnected() {
        return components == 1;
    }
        
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind Alice(n), Bob(n);

        int edgesNeed=0;
        // Process type 3 edges first
        for (vector<int>& e: edges) {
            if (e[0]==3) {
                edgesNeed+=(Alice.Union(e[1], e[2]) | Bob.Union(e[1], e[2]));
            }
        }
        // Process type 1 and type 2 edges
        for (vector<int>& e: edges){
            if (e[0]==1) edgesNeed+=Alice.Union(e[1], e[2]);
            else if (e[0]==2) edgesNeed+=Bob.Union(e[1], e[2]);
        }

        if (Alice.isConnected() && Bob.isConnected())
            return edges.size()-edgesNeed;
        return -1;
    }
};
