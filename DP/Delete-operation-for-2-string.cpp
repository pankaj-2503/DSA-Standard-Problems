class Solution {
public:
// Time complexity of O(N*M) , space complexity - O(N*M)
    int lcs(string &word1,string &word2){
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        int ans= lcs(word1,word2);
        return n-ans+m-ans;

    }
};