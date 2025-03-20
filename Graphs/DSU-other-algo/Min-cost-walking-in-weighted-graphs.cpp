// DSU Question

// TC: O(n+q), SC: O(n)

class Solution {
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            vector<int>parent(n),cost(n,-1);
            iota(parent.begin(),parent.end(),0);
    
            function<int(int)>find=[&](int node){
                if(parent[node]==node) return node;
                return parent[node]=find(parent[node]);
            };
            
            for(auto i:edges){
                int src=i[0],target=i[1],wt=i[2];
    
                int srcroot=find(src);
                int targetroot=find(target);
                
                cost[targetroot]&=wt;
                if(srcroot!=targetroot){
                    cost[targetroot]&=cost[srcroot];
                    parent[srcroot]=targetroot;
                }
            }
            vector<int>res;
            for(auto i:query){
                int f=i[0],s=i[1];
                if(f==s) res.push_back(0);
                else if(find(f)!=find(s)) res.push_back(-1);
                else{
                    res.push_back(cost[find(f)]);
                }
            }
            return res;
        }
    };