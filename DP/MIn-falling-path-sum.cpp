class Solution {
public:
// Recursion -> Time complexity - O(3^N) , space complexity - O(N), recursion stack
    int solve(int i,int j,vector<vector<int>>&matrix){
        // base case
        int n=matrix.size(),m=matrix[0].size();
        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[0][j];

        int up=matrix[i][j] + solve(i-1,j,matrix);
        int leftDiagonal=matrix[i][j]+solve(i-1,j-1,matrix);
        int rightDiagonal=matrix[i][j]+ solve(i-1,j+1,matrix);
        return min({up,leftDiagonal,rightDiagonal});


    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int mini=INT_MAX;
        for(int j=0;j<m;j++){
            int ans=solve(n-1,j,matrix);
            mini=min(mini,ans);
        }
        return mini;
    }
};

// memoisation
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        // base case
        int n=matrix.size(),m=matrix[0].size();
        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int up=matrix[i][j] + solve(i-1,j,matrix,dp);
        int leftDiagonal=matrix[i][j]+solve(i-1,j-1,matrix,dp);
        int rightDiagonal=matrix[i][j]+ solve(i-1,j+1,matrix,dp);
        return dp[i][j]=min({up,leftDiagonal,rightDiagonal});


    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mini=INT_MAX;
        for(int j=0;j<m;j++){
            int ans=solve(n-1,j,matrix,dp);
            mini=min(mini,ans);
        }
        return mini;
    }
};


// Tabulation -> time complexity - O(N*N), space complexity - O(N*N)

class Solution {
public:  
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int j=0;j<n;j++) dp[0][j]=matrix[0][j];

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int left,right,up;

                up=dp[i-1][j];

                if(j>0){
                    left=dp[i-1][j-1];
                }else left=INT_MAX;

                if(j<n-1){
                    right=dp[i-1][j+1];
                }else right=INT_MAX;

                dp[i][j]=matrix[i][j]+ min({left,right,up});


            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }

};

// Space optimisation
class Solution {
public:  
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>prev(n,0);
        vector<int>curr(n,0);
        for(int j=0;j<n;j++) prev[j]=matrix[0][j];

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int left,right,up;

                up=prev[j];

                if(j>0){
                    left=prev[j-1];
                }else left=INT_MAX;

                if(j<n-1){
                    right=prev[j+1];
                }else right=INT_MAX;

                curr[j]=matrix[i][j]+ min({left,right,up});


            }
            prev=curr;
        }

        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,prev[j]);
        }
        return mini;

    }

};

