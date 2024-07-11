class Solution{
    public:
    // Recursion -> time complexity - O(exponential) since we are at same index several time, space complexity - O(N);
    // Memoisation -> Time complexity - O(N*N) , space complexity - O(N*N)+O(N) for recursion stack
    int solve(int index,int price[],int N,vector<vector<int>>&dp){
        if(index==0){
            return N*price[0];
        }
        
        if(dp[index][N]!=-1) return dp[index][N];
        
        int notpick=solve(index-1,price,N,dp);
        int pick=INT_MIN;
        int rodLength=index+1;
        if(rodLength<=N) pick=price[index]+solve(index,price,N-rodLength,dp);
        return dp[index][N]=max(pick,notpick);
        
    }
    
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,price,n,dp);
    }
};

// Tabulation approach -> Time complexity - O(N*N) , space complexity - O(N*N)

 int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int index=0;index<n;index++){
            for(int N=0;N<=n;N++ ){
                if(index==0){
                    dp[index][N]=price[0]*N;continue;
                }
                
                int notpick=dp[index-1][N];
                int pick=INT_MIN;
                int rodLength=index+1;
                if(rodLength<=N) pick=price[index]+dp[index][N-rodLength];
                dp[index][N]=max(pick,notpick);
            }
        }
        return dp[n-1][n];
    }