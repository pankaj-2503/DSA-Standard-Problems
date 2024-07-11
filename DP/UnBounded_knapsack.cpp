class Solution{
    public:
    // Recursion -> Time complexity - O(exponential) since we are staying at same index, space complexity - O(N)
    int solve(int index,int W,int val[],int wt[]){
        // base case
        if(index==0){
            return (W/wt[0])*(val[0]);
        }
        
        int notpick=solve(index-1,W,val,wt);
        int pick=INT_MIN;
        if(wt[index]<=W) pick=val[index]+solve(index,W-wt[index],val,wt);
        return max(pick,notpick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        return solve(N-1,W,val,wt);
    }
};


class Solution{
    public:
    // Memoisation -> time complexity - O(N*W) , space complexity - O(N*W) + O(N),recursion stack
    int solve(int index,int W,int val[],int wt[],vector<vector<int>>&dp){
        // base case
        if(index==0){
            return (W/wt[0])*(val[0]);
        }
        
        if(dp[index][W]!=-1) return dp[index][W];
        
        int notpick=solve(index-1,W,val,wt,dp);
        int pick=INT_MIN;
        if(wt[index]<=W) pick=val[index]+solve(index,W-wt[index],val,wt,dp);
        
        return dp[index][W]=max(pick,notpick);
        
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return solve(N-1,W,val,wt,dp);
    }
};

// Tabulation -> Time complexity - O(N*W) , space complexity - O(N*W)

 int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,0));
        
        for(int index=0;index<N;index++){
            for(int cap=0;cap<=W;cap++){
                if(index==0){
                    dp[index][cap]=(cap/wt[0])*(val[0]);continue;
                }
                int notpick=dp[index-1][cap];
                int pick=INT_MIN;
                if(wt[index]<=cap) pick=val[index]+dp[index][cap-wt[index]];
                dp[index][cap]=max(pick,notpick);
            }
        }
        return dp[N-1][W];
    }


    // Space optimisation -> space complexity - O(N)
     int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int>curr(W+1,0);
        
        
        for(int index=0;index<N;index++){
            for(int cap=0;cap<=W;cap++){
                if(index==0){
                    curr[cap]=(cap/wt[0])*(val[0]);continue;
                }
                int notpick=curr[cap];
                int pick=INT_MIN;
                if(wt[index]<=cap) pick=val[index]+curr[cap-wt[index]];
                curr[cap]=max(pick,notpick);
            }
        }
        return curr[W];
    }

// Space optimisation -> O(N)

int cutRod(int price[], int n) {
    //code here
    vector<int>curr(n+1,0);
    for(int index=0;index<n;index++){
        for(int N=0;N<=n;N++ ){
            if(index==0){
                curr[N]=price[0]*N;continue;
            }
            
            int notpick=curr[N];
            int pick=INT_MIN;
            int rodLength=index+1;
            if(rodLength<=N) pick=price[index]+curr[N-rodLength];
            curr[N]=max(pick,notpick);
        }
    }
    return curr[n];
}