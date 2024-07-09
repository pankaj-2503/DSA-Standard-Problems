class Solution {
public:
// Recursion -> Time complexity - O(2^N) , space complexity - O(N)
    int solve(int index,int amount,vector<int>&coins){
        // base case 
        if(index==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }
        

        int pick=0;
        if(coins[index]<=amount) pick=solve(index,amount-coins[index],coins);
        int notpick=solve(index-1,amount,coins);

        return pick+notpick;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return solve(n-1,amount,coins);
    }
};

// Memoisation -> time complexity - O(N*target) , space complexity - O(N*target)+O(N) for recursion
class Solution {
public:
    int solve(int index,int amount,vector<int>&coins,vector<vector<int>>&dp){
        // base case 
        if(index==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }

        if(dp[index][amount]!=-1) return dp[index][amount];

        

        int pick=0;
        if(coins[index]<=amount) pick=solve(index,amount-coins[index],coins,dp);
        int notpick=solve(index-1,amount,coins,dp);

        return dp[index][amount]=pick+notpick;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};

// Tabulation -> Time complexity - O(N*target) , space complexity - O(N*target)
class Solution {
public:
   
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int index=0;index<n;index++){
            for(int target=0;target<=amount;target++){
                if(index==0){
                    if(target%coins[index]==0) dp[index][target]=1;continue;
                }
                int pick=0;
                if(coins[index]<=target) pick=dp[index][target-coins[index]];
                int notpick=dp[index-1][target];
                dp[index][target]=pick+notpick;
            }
        }


        return dp[n-1][amount];
    }
};

// Space optimised -> space complexity - O(2*N)
class Solution {
public:
   
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);
        
        for(int index=0;index<n;index++){
            for(int target=0;target<=amount;target++){
                if(index==0){
                    if(target%coins[index]==0) curr[target]=1;continue;
                }
                int pick=0;
                if(coins[index]<=target) pick=curr[target-coins[index]];
                int notpick=prev[target];
                curr[target]=pick+notpick;
            }
            prev=curr;
        }


        return prev[amount];
    }
};