// In this problem we have given 2d matrix and we have to reach from top-left to bottom-right
// we can move down and right , also there is obstacle present return no. of ways to reach destination

class Solution {
public:
// Recursion approach
// Time complexity - O(2^(N+M)) , space complexity - O(N+M) ->recursion stack
    int solve(int i,int j,vector<vector<int>>&obstacleGrid){
        // base case
        if(i==0 && j==0){
            if(obstacleGrid[i][j]!=1) return 1;
            else return 0;
        }
        if(i<0 || j<0) return 0;


        int up=0,left=0;
        if(obstacleGrid[i][j]==0) up=solve(i-1,j,obstacleGrid);
        if(obstacleGrid[i][j]==00) left=solve(i,j-1,obstacleGrid);

        return up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        return solve(n-1,m-1,obstacleGrid);
    }
};

// Memoisation
// Time complexity - O(N*M) , space complexity - O(N*M)
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        // base case
        if(i==0 && j==0){
            if(obstacleGrid[i][j]!=1) return 1;
            else return 0;
        }
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];


        int up=0,left=0;
        if(obstacleGrid[i][j]==0) up=solve(i-1,j,obstacleGrid,dp);
        if(obstacleGrid[i][j]==00) left=solve(i,j-1,obstacleGrid,dp);

        return dp[i][j]=up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,obstacleGrid,dp);
    }
};

// Tabulation
// Time complexity - O(N*M) , space complexity - O(N*M)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0 && obstacleGrid[i][j]==0){
                    dp[i][j]=1;continue;
                }
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else{
                    int left=0,up=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=left+up;

                }
            }
        }
        return dp[n-1][m-1];
    }
};

// Space optimised - space complexity - O(2*N)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<int>prev(m,0),curr(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0 && obstacleGrid[i][j]==0){
                    curr[j]=1;continue;
                }
                if(obstacleGrid[i][j]==1) curr[j]=0;
                else{
                    int left=0,up=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=curr[j-1];
                    curr[j]=left+up;

                }
            }
            prev=curr;
        }
        return prev[m-1];
    }
};