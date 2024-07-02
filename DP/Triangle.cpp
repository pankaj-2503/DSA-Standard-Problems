class Solution {
public:
// Recursion -> Time complexity - O(2^N) , space complexity - O(N)->recursion stack
    int solve(int i,int j,vector<vector<int>>&triangle){
        //base case
        int n=triangle.size();
        if(i==n-1){
            return triangle[i][j];
        }
        int down=triangle[i][j]+solve(i+1,j,triangle); 
        int diagonal=triangle[i][j]+solve(i+1,j+1,triangle);
        return min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        return solve(0,0,triangle);
    }
};

// Memoisation
// Time complexity - O(N*N) , space complexity - O(N*N)
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        //base case
        int n=triangle.size();
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down=triangle[i][j]+solve(i+1,j,triangle,dp); 
        int diagonal=triangle[i][j]+solve(i+1,j+1,triangle,dp);
        return dp[i][j]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,triangle,dp);
    }
};

// Tabulation
// Time complexity - O(N*N) , space complexity - O(N*N)

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        // filling last row with triangle's value and moving bottom to top
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
              int down=triangle[i][j]+dp[i+1][j];
              int diagonal=triangle[i][j]+dp[i+1][j+1];

              dp[i][j]=min(down,diagonal);
            }
        }
        
        return dp[0][0];
    }
};

// Space optimised 
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>front(n,0);
        vector<int>curr(n,0);
        // filling last row with triangle's value and moving bottom to top
        for(int j=0;j<n;j++){
            front[j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
              int down=triangle[i][j]+front[j];
              int diagonal=triangle[i][j]+front[j+1];

              curr[j]=min(down,diagonal);
            }
            front=curr;
        }
        
        return front[0];
    }
};