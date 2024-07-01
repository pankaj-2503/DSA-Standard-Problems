  // Frog wants to reach 0 to n-1 stair using minimum energy , he can jump 1 or 2 step
  class Solution{
    public:
    // Recursion 
    // time complexity - O(2^n), space complexity - O(1)
    int solve(int ind,vector<int>&height,vector<int>&dp){
        if(ind==0) return 0;
        
        int jumpTwo = INT_MAX;
        int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
        
        return min(jumpOne, jumpTwo);
    }
    int minimumEnergy(vector<int>& height, int n) {
        
        return solve(n-1,height,dp);
    }
  };

  // Memoization 
  // Time complexity - O(N), space compelxity - O(N)

  class Solution{
     public:
    int solve(int ind,vector<int>&height,vector<int>&dp){
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int jumpTwo = INT_MAX;
        int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
        
        return dp[ind]=min(jumpOne, jumpTwo);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return solve(n-1,height,dp);
    }
  }

  // Tabulation 
  // Time complexity - O(N), space complexity - O(N)
class Solution{
    public:
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int ind=1;ind<n;ind++){
        int jumpTwo = INT_MAX;
            int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
            if(ind>1)
                jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
        
            dp[ind]=min(jumpOne, jumpTwo);
    }

};


// Space optimisation
// Time commplexity - O(N), space complexity - O(1);
  int minimumEnergy(vector<int>& height, int n) {
        // Code here
          int prev=0;
          int prev2=0;
          for(int i=1;i<n;i++){
              
              int jumpTwo = INT_MAX;
              int jumpOne= prev + abs(height[i]-height[i-1]);
              if(i>1)
                jumpTwo = prev2 + abs(height[i]-height[i-2]);
            
              int cur_i=min(jumpOne, jumpTwo);
              prev2=prev;
              prev=cur_i;
                
          }
          return prev;
    }
