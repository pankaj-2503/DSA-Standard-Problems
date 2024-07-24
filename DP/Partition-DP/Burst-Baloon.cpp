class Solution {
public:
// TC: O(N^3) , SC: O(N^2)+O(N)
    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mx=-1e9;

        for(int k=i;k<=j;k++){
            int cost=nums[i-1]*nums[k]*nums[j+1];
            int remainingCoins=solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
            mx=max(mx,cost+remainingCoins);

        }
        return dp[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    
        return solve(1,n,nums,dp);
    }
};

// Tabulation approach -> // TC: O(N^3) , SC: O(N^2)
class Solution {
public:
   
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int mx=-1e9;
                for(int k=i;k<=j;k++){
                    int coins=nums[i-1]*nums[k]*nums[j+1];
                    int remainingCoins=dp[i][k-1]+dp[k+1][j];
                    mx=max(mx,coins+remainingCoins);
                }
                dp[i][j]=mx;
            }
        }
        return dp[1][n];
    
       
    }
};