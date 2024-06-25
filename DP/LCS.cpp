class Solution {
public:
// Recursion
// Time complexity- O(2^N) ,space complexity-O(1)
    int solve(int ind1,int ind2,string &p,string &q){
        // base case
        if(ind1<0 || ind2<0) return 0;
        
        if(p[ind1]==q[ind2]) return 1+solve(ind1-1,ind2-1,p,q);
        else return max(solve(ind1-1,ind2,p,q),solve(ind1,ind2-1,p,q));
     }
    int longestCommonSubsequence(string p, string q) {
        int n=p.size(),m=q.size();
        return solve(n-1,m-1,p,q);
    }
};

// Memoization
// Time complexity - O(N*M), space complexity - O(N*M)+ O(N+M)
class Solution {
public:
    int solve(int ind1,int ind2,string &p,string &q,vector<vector<int>>&dp){
        // base case
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(p[ind1]==q[ind2]) return dp[ind1][ind2]=1+solve(ind1-1,ind2-1,p,q,dp);
        else return dp[ind1][ind2]=max(solve(ind1-1,ind2,p,q,dp),solve(ind1,ind2-1,p,q,dp));
     }
    int longestCommonSubsequence(string p, string q) {
        int n=p.size(),m=q.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,p,q,dp);
    }
};

// Tabulation
// Time complexity - O(N*M) , space complexity - O(N*M) 

class Solution {
public:
    
    int longestCommonSubsequence(string p, string q) {
        int n=p.size(),m=q.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==q[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

// Space optimisation
// Time complexity - O(N*M) , space complexity - O(M)

class Solution {
public:
    
    int longestCommonSubsequence(string p, string q) {
        int n=p.size(),m=q.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>prev(m+1,0),cur(m+1,0);
        // prev -> dp[i-1][] , cur -> dp[i][]
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==q[j-1]){
                    cur[j]=1+prev[j-1];
                }
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
};