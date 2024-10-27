class Solution {
public:
// TC: O(N*M) similar SC
    int dfs(int i,int j,vector<vector<int>>& matrix, vector<vector<int>>&dp){
        int n=matrix.size(),m=matrix[0].size();
        if(i>=n || j>=m || matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int right=dfs(i,j+1,matrix,dp);
        int diagonal=dfs(i+1,j+1,matrix,dp);
        int down=dfs(i+1,j,matrix,dp);

        return dp[i][j]=min({right,diagonal,down})+1;

        

    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=dfs(i,j,matrix,dp);
            }
        }
        return ans;

    }
};

// top -down appraoch with TC -> O(N*M)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    dp[i+1][j+1]=min({dp[i+1][j],dp[i][j+1],dp[i][j]})+1;
                    ans+=dp[i+1][j+1];
                }
            }
        }
        
        return ans;
    }
};