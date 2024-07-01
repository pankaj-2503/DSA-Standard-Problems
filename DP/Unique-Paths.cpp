class Solution{
    public:
    // Time complexity - O(2^(N+M))
     int solve(int i,int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        int up=solve(i-1,j);
        int left=solve(i,j-1);
        return left+up;
    }
    int uniquePaths(int m, int n) {
       return  solve(m-1,n-1);
    }
};

// Memoisation
// Space Complexity: O(M*N) , Time Complexity: O(M*N)
int solve(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(i-1,j,dp);
        int left=solve(i,j-1,dp);
        return dp[i][j]=left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return  solve(m-1,n-1,dp);
    }

// Tabulation
// Space Complexity: O(M*N) , Time Complexity: O(M*N)


int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(i==0 && j==0){
                dp[i][j]=1;continue;
               }
               int left=0,up=0;
               if(j>0) left=dp[i][j-1];
               if(i>0) up=dp[i-1][j];
               dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
      
    }

int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
               dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
      
    }

// Space optimisation - O(2N)
 int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        vector<int>curr(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(i==0 && j==0){
                 curr[j]=1;continue;
               }
               int left=0,up=0;
               if(i>0) up=prev[j];
               if(j>0) left=curr[j-1];
               curr[j]=left+up;
            }
            prev=curr;

        }
        return prev[n-1];
      
    }