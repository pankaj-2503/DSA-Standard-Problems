class Solution{
 public:
 // Recursion
 // Time complexity- O(2^N) , space complexity- O(N+M)
    int ans=0;
    int solve(int ind1,int ind2,string &p,string &q){
        if(ind1<0 || ind2<0) return 0;
        int include=0;
        if(p[ind1]==q[ind2]){
            include=1+solve(ind1-1,ind2-1,p,q);
            ans=max(ans,include);
            return include;
        }
        int ans1=solve(ind1-1,ind2,p,q);
        int ans2=solve(ind1,ind2-1,p,q);
        return include;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
         solve(n-1,m-1,S1,S2);
         return ans;
        
    }
};

// Memoization
// Time complexity - O(N*M) , space complexity - O(N*M)+O(N+M)
   int ans=0;
    int solve(int ind1,int ind2,string &p,string &q, vector<vector<int>>&dp){
        
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        
        int include=0;
        if(p[ind1]==q[ind2]){
            include=1+solve(ind1-1,ind2-1,p,q,dp);
            ans=max(ans,include);
        }
        
        int ans1=solve(ind1-1,ind2,p,q,dp);
        int ans2=solve(ind1,ind2-1,p,q,dp);
        
        return dp[ind1][ind2]=include;
    }

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
         solve(n-1,m-1,S1,S2,dp);
         return ans;
        
    }

// Tabulation 
// Time Complexity: O(N*M) , space complexity - O(N*M)

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return ans;
    }


// space optimisatoin
// Space complexity - O(M)
int lcs(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    
    // Initialize two vectors to store previous and current row values
    vector<int> prev(m+1, 0); // Stores values of the previous row
    vector<int> cur(m+1, 0);  // Stores values of the current row

    int ans = 0; // Initialize the answer variable to store the maximum LCS length found
    
    // Loop through both strings
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                int val = 1 + prev[j-1]; // Characters match, increment substring length
                cur[j] = val; // Update the current row with the new value
                ans = max(ans, val); // Update the maximum substring length found so far
            }
            else
                cur[j] = 0; // Characters don't match, substring length becomes 0
        }
        prev = cur; // Update the previous row with the values of the current row
    }
    
    return ans; // Return the length of the Longest Common Substring
}
