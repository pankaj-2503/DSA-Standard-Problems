
class Solution {
public:
// Recursion -> Time complexity - O(2^(N+M)) , space complexity - O(N+M) -> recursions stack
    int solve(int i,int j,vector<vector<int>>&grid){
        //base case
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0) return 1e9;
        
        int left=grid[i][j]+solve(i,j-1,grid);
        int up=grid[i][j]+solve(i-1,j,grid);

        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        return solve(n-1,m-1,grid);
    }
};

// Memoisation
// Time complexity - O(N*M) , space complexity - O(N*M)+O(M+N)
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        //base case
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left=grid[i][j]+solve(i,j-1,grid,dp);
        int up=grid[i][j]+solve(i-1,j,grid,dp);

        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};


// Tabulation
// Time complexity - O(N*M) , space complexity - O(N*M)
class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=grid[i][j],left=grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up+=1e9;
                    
                    if(j>0) left+=dp[i][j-1];
                    else left+=1e9;
                    dp[i][j]=min(up,left);
                    
                } 
            }
        }

        return dp[n-1][m-1];
    }
};

// Space optimisation
// Space complexity- O(2*M)
class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0) curr[j]=grid[i][j];
                else{
                    int up=grid[i][j],left=grid[i][j];
                    if(i>0) up+=prev[j];
                    else up+=1e9;
                    
                    if(j>0) left+=curr[j-1];
                    else left+=1e9;
                    curr[j]=min(up,left);
                    
                } 
            }
            prev=curr;
        }

        return prev[m-1];
    }
};
