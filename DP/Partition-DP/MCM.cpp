class Solution{
    public:
    // f(i,j) -> represents minimum no. of operation to get the product of matrices Ai..Aj
    // Recursive approach : TC-O(2^N) , SC: O(N)
     int solve(int i,int j,int arr[]){
        if(i==j) return 0;
        
        int mini=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int ans=solve(i,k,arr)+solve(k+1,j,arr)+arr[i-1]*arr[k]*arr[j];
            mini=min(mini,ans);
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i=1,j=N-1;
        return solve(i,j,arr);
    }
};

// Memoisation -> TC:O(N^3) , SC:O(N*N)+O(N)
int solve(int i,int j,int arr[],vector<vector<int>>&dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int ans=solve(i,k,arr,dp)+solve(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j];
            mini=min(mini,ans);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i=1,j=N-1;
        vector<vector<int>>dp(N,vector<int>(N,-1));
        return solve(i,j,arr,dp);
    }

// dp[i][j]-> represent minimum operation to get product of (Ai,Ai+1,Ai+2.....Aj)
// Tabulation -> TC:O(N*N*N) , SC:O(N*N)
 int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(N,1e9));
        for(int i=1;i<N;i++) dp[i][i]=0; // that is when i and j are same 
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],arr[i-1]*arr[j]*arr[k] + dp[i][k]+dp[k+1][j]);
                }
            }
        }
        return dp[1][N-1];
    }

