class Solution {
public:
   // Time complexity - O(2^N), space complexity - O(N)
        // represent max profit generated from 0 to n where buy tell buy/sell stock
    int solve(int index,int buy,vector<int>&prices,int n){ 

        if(index==n) return 0;

        int profit=0, op1,op2;
        
        if(buy==0){ // we can buy the stock
          // don't do any transaction
          op1=solve(index+1,0,prices,n);
          // buy the stock
          op2=solve(index+1,1,prices,n) - prices[index];
        }

        if(buy==1){// we can sell the stock
          // dont' do any transaction
          op1=solve(index+1,1,prices,n);
          // sell the stock
          op2=solve(index+1,0,prices,n) + prices[index];
        }

        profit=max(op1,op2);
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return solve(0,0,prices,n);
    }
};

// Memoisation -> Time complexity - O(2*n) , space complexity - O(2*N)+O(N)
class Solution {
public:
   
        // represent max profit generated from 0 to n where buy tell buy/sell stock
    int solve(int index,int buy,vector<int>&prices,int n,vector<vector<int>>&dp){ 

        if(index==n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];

        int profit=0, op1,op2;
        
        if(buy==0){ // we can buy the stock
          // don't do any transaction
          op1=solve(index+1,0,prices,n,dp);
          // buy the stock
          op2=solve(index+1,1,prices,n,dp) - prices[index];
        }

        if(buy==1){// we can sell the stock
          // dont' do any transaction
          op1=solve(index+1,1,prices,n,dp);
          // sell the stock
          op2=solve(index+1,0,prices,n,dp) + prices[index];
        }

        profit=max(op1,op2);
        return dp[index][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,0,prices,n,dp);
    }
};

// Tabulation -> Time complexity - O(2*n) , space complexity - O(2*N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // base case
        dp[n][0]=dp[n][1]=0;

        for(int index=n-1;index>=0;index--){
            int profit=0;
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                    profit=max(dp[index+1][0],-prices[index]+dp[index+1][1]);
                }else{
                    profit=max(dp[index+1][1],prices[index]+dp[index+1][0]);

                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][0];
    }
};

// Space optimisation - > space complexity constant
class Solution {
public:
    int maxProfit(vector<int>& Arr) {
    int n=Arr.size();
    vector<long> ahead(2, 0);
    vector<long> cur(2, 0);

    // Base condition: When there are no stocks left, the profit is 0.
    ahead[0] = ahead[1] = 0;

    

    // Loop through the array in reverse order
    for (int ind = n - 1; ind >= 0; ind--) {
        int profit=0;
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + ahead[1], Arr[ind] + ahead[0]);
            }
            cur[buy] = profit;
        }

        ahead = cur; // Update the "ahead" array with the current values
    }

    // The maximum profit is stored in cur[0] after all calculations
    return cur[0];
    }
};