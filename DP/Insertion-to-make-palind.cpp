class Solution {
public:
// Time Complexity: O(N*N) , same space complexity
    int lcs(string p,string q){
        int n=p.size(),m=q.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==q[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromicSubseq(string s){
       string t=s;
       reverse(s.begin(),s.end());
       return lcs(s,t);
    }
    int minInsertions(string s) {
        int n=s.size();
       int ans= longestPalindromicSubseq(s);
       return n-ans;

    }
};

// Space optimisation -> Space complexity - O(N)
class Solution {
public:
    int lcs(string p,string q){
        int n=p.size(),m=q.size();
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==q[j-1]){
                    curr[j]=1+prev[j-1];
                }else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n];
    }
    int longestPalindromicSubseq(string s){
       string t=s;
       reverse(s.begin(),s.end());
       return lcs(s,t);
    }
    int minInsertions(string s) {
        int n=s.size();
       int ans= longestPalindromicSubseq(s);
       return n-ans;

    }
};