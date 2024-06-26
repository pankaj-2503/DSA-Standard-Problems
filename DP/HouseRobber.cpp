// Recursion 
// Time complexity - O(2^N) , space complexity - O(N);
class Solution {
public:

    int solve(vector<int>&nums,int ind){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        int pick=nums[ind]+solve(nums,ind-2);
        int notpick=0+solve(nums,ind-1);
        return max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,n-1);
    }
};

// Memoization
// Time Complexity - O(N) , space complexity - O(N)

class Solution {
public:
    int solve(vector<int>&nums,int ind,vector<int>&dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+solve(nums,ind-2,dp);
        int notpick=0+solve(nums,ind-1,dp);
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,n-1,dp);
    }
};

// Tabulation
// Time Complexity - O(N) , space complexity - O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=dp[i-2];
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];

    }
};

// Space optimised 
// Time complexity - O(N) , space complexity - O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
      
      
        int prev=nums[0];
        int prev2=0;

        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;

    }
};