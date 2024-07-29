#define ll long long
class Solution {
public:
// using floyd warshall algorithm to find shortest distance from each node to every other node 
// TC: O(26^3)+O(N) , SC: O(26^2)
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>>dist(26,vector<ll>(26,1e9));
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            ll x=original[i]-'a';
            ll y=changed[i]-'a';
            ll z=cost[i];
            dist[x][y]=min(dist[x][y],z);
        }
        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dist[i][j]=min(dist[i][via]+dist[via][j],dist[i][j]);
                }
            }
        }

        ll ans=0;
        int n=source.size();
        for(int i=0;i<n;i++){
            int x=source[i]-'a';
            int y=target[i]-'a';
            if(x!=y){
                if(dist[x][y]!=1e9) ans+=dist[x][y];
                else return -1;
            }
        }
        return ans;
    }
};