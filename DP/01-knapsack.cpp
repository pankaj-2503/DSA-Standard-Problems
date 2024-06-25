class Solution{
    public:
    // Recursion
    // Time complexity -O(2^N) , space complexity - O(N)
    int solve(int ind,int W,int wt[],int val[]){
        // base case
        
        if(ind==0){
            if(wt[ind]<=W) return val[ind];
            return 0;
        }
        int pick=0;
        int notpick=0+solve(ind-1,W,wt,val);
        
        if(wt[ind]<=W) pick=val[ind]+solve(ind-1,W-wt[ind],wt,val);
        return max(pick,notpick);
        
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return solve(n-1,W,wt,val);
    }
};

// Memoization
// Time complexity - O(N*W) , space complexity - O(N*W)
 int solve(int ind,int W,int wt[],int val[],vector<vector<int>>&dp){
        // base case
        
        if(ind==0){
            if(wt[ind]<=W) return val[ind];
            return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int pick=0;
        int notpick=0+solve(ind-1,W,wt,val,dp);
        
        if(wt[ind]<=W) pick=val[ind]+solve(ind-1,W-wt[ind],wt,val,dp);
        return dp[ind][W]=max(pick,notpick);
        
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return solve(n-1,W,wt,val,dp);
    }

// Tabulation
 int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
      vector<vector<int> > K(n + 1, vector<int>(W + 1));

    // Build table K[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1]
                                  + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
    }