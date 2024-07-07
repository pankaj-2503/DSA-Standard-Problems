class Solution{
    public:
    // Recursion -> Time complexity - O(N^target) , space complexity - O(N)
     int solve(vector<int>&coins,int target,int index){
        // base case
        if(index==0){
            if(target%coins[index]==0) return target/coins[index];
            else return 1e9;
        }
        
       
       
        // include
        int pick=1e9;
        if(coins[index]<=target){
           pick = 1+solve(coins,target-coins[index],index);
        }
        // exclude
        int notpick=solve(coins,target,index-1);

        return min(pick,notpick);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       
        int ans= solve(coins,amount,n-1);
        if(ans==1e9) return -1;
        return ans;
    }

};


class Solution {
public:
// Memoisation - > Time complextiy - O(N*target) , space complexity - O(N*target)+O(N)
    int solve(vector<int>&coins,int target,int index,vector<vector<int>>&dp){
        // base case
        if(index==0){
            if(target%coins[index]==0) return target/coins[index];
            else return 1e9;
        }
        
        // dp base case
        if(dp[index][target]!=-1) return dp[index][target];
       
        // include
        int pick=1e9;
        if(coins[index]<=target){
           pick = 1+solve(coins,target-coins[index],index,dp);
        }
        // exclude
        int notpick=solve(coins,target,index-1,dp);

        return dp[index][target]=min(pick,notpick);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= solve(coins,amount,n-1,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};


// Tabulation -> Time Complexity: O(N*T) , Space Complexity: O(N*T)
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0) dp[0][target]=target/coins[0];
            else dp[0][target]=1e9;
        }

        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                int pick=1e9;
                if(coins[i]<=target) pick=1+dp[i][target-coins[i]];
                int notpick=dp[i-1][target];
                dp[i][target]=min(pick,notpick);
            }
        }
        if(dp[n-1][amount]==1e9) return -1;
        else return dp[n-1][amount];
        
    }
};


// Space optimised -> space complexity - O(2*N)
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();
        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);

        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0) prev[target]=target/coins[0];
            else prev[target]=1e9;
        }

        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                int pick=1e9;
                if(coins[i]<=target) pick=1+curr[target-coins[i]];
                int notpick=prev[target];
                curr[target]=min(pick,notpick);
            }
            prev=curr;
        }
        if(prev[amount]==1e9) return -1;
        else return prev[amount];
        
    }
};