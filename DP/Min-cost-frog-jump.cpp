  class Solution {
  public:
    int solve(vector<int>&height,int ind,int k){
        if(ind==0) return 0;
        int mnSteps=INT_MAX;
        for(int i=1;i<=k;i++){
            if(ind-i>=0){
                int jump=solve(height,ind-i,k)+abs(height[ind]-height[ind-i]);
                mnSteps=min(jump,mnSteps);
            }
        }
        return mnSteps;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        return solve(height,n-1,k);
    }
};
  
  // Memoization 
  // Time complexity - O(N*k) , space complexity - O(N)
 int solve(vector<int>&height,int ind,int k,vector<int>&dp){
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int mnSteps=INT_MAX;
        for(int i=1;i<=k;i++){
            if(ind-i>=0){
                int jump=solve(height,ind-i,k,dp)+abs(height[ind]-height[ind-i]);
                mnSteps=min(jump,mnSteps);
            }
        }
        return dp[ind]=mnSteps;
    }
int minimizeCost(vector<int>& height, int n, int k) {
    // Code here
    vector<int>dp(n+1,-1);
    return solve(height,n-1,k,dp);
}

// Tabulation
// Time complexity - O(N*k) , space complexity - O(N)

int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n);
        dp[0]=0;
        // loop for each index
        for(int i=1;i<n;i++){
            int mnSteps=INT_MAX;
            // loop for k possible jumps
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    int jump=dp[i-j]+abs(height[i]-height[i-j]);
                    mnSteps=min(jump,mnSteps);
                }
            }
            dp[i]=mnSteps;
        }
        return dp[n-1];
    }