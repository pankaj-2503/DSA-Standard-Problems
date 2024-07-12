class Solution {
public:
// Time Complexity: O(N*M) , Space Complexity: O(N*M) + O(N+M)
    int solve(string s, string t,int i,int j,vector<vector<int>> &dp){
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int result=0;
    if(s[i]==t[j]){
        result=(solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp));
    }
    else{
        result=solve(s,t,i-1,j,dp);
    }
    return dp[i][j]=result;
}
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        int i=s.size();
        int j=t.size();
        return solve(s,t,i-1,j-1,dp);
        
    }
};

// Tabulation
class Solution {
public:
// Time Complexity: O(N*M) , Space Complexity: O(N*M) 
    int mod=1e9+7;
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       
        
        // empty string s2 can be matched with any string s1
        for(int i=0;i<=n;i++) dp[i][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
        
    }
};

// Space optimised 
class Solution {
public:
// Time Complexity: O(N*M) , Space Complexity: O(N) 
    int mod=1e9+7;
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int>prev(m+1,0);
       
        
        // empty string s2 can be matched with any string s1
        prev[0]=1;

        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){ // to prevent overwriting prev values
                if(s[i-1]==t[j-1]){
                    prev[j]=(prev[j-1]+prev[j])%mod;
                }else{
                    prev[j]=prev[j];
                }
            }
        }
        return prev[m];
        
    }
};